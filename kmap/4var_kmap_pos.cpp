#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

typedef vector<int> vi;
typedef vector<ll> vl;

typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)

#define fr first 
#define sc second
#define pb push_back
#define mp make_pair

#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

vi gc = {0, 1, 3, 2}; // gray code sequence

void deb()
{
    cout << "debugging input" << nl;
    // fur(i, 0, 3) {
        // fur(j, 0, 3)
            // cout << s[i][j] << ' ';
        // cout << nl;
    // }
    // cout << nl;


    cout << "debugging prefix sum array" << nl;
    // fur(i, 0, 3) {
        // fur(j, 0, 3)
            // cout << s[i][j] << ' ';
        // cout << nl;
    // }
    // cout << nl;

    cout << "debugging dims" << nl;
    // for(auto u : dims)
        // cout << u.area << ' ' << u.l << ' ' << u.w << nl;
    // cout << nl;

    cout << "debugging final groups" << nl;
    // for(auto u : final_grps)
    // {
        // cout << "(" << u.x << ", " << u.y << "); (" << u.X << ", " << u.Y << ")" << nl;
    // }
    // cout << nl;
}

struct rect
{
    int l;
    int w;
    int area;

    rect(int i, int j) {
        l = i;
        w = j;
        area = l * w;
    }

    bool operator < (const rect& oth) {
        if(area != oth.area)
            return area < oth.area;
        else if(l != oth.l)
            return l < oth.l;
        else
            return w < oth.w;
    }
};

struct group
{
    int x, y, X, Y;
    int area;

    group(int a, int b, int c, int d) {
        x = a;
        y = b;
        X = c;
        Y = d;

        area = (X - x + 1) * (Y - y + 1);
    }

    bool operator < (const group& oth) {
        return area < oth.area;
    }

    bool operator > (const group& oth) {
        return area > oth.area;
    }
};

int sum(ll r, ll c, ll rr, ll cc, const vector<vector<int>>& s)
{
    return s[rr][cc] - (r > 0 ? s[r - 1][cc] : 0) - (c > 0 ? s[rr][c - 1] : 0) + (r > 0 && c > 0 ? s[r - 1][c - 1] : 0);
}

string exp_pos(int l, int r, bool row)
{
    if(l >= 4 && r >= 4) {
        l -= 4;
        r -= 4;
    }

    string a, b;
    if(row) {
        a = "p";
        b = "q";
    }
    else {
        a = "r";
        b = "s";
    }

    if(l == 0) {
        if(r - l + 1 == 1)
            return a + " + " + b;
        else if(r - l + 1 == 2)
            return a;
        else if(r - l + 1 == 4)
            return "true";
    }
    else if(l == 1) {
        if(r - l + 1 == 1)
            return a + " + " + b + "'";
        else if(r - l + 1 == 2)
            return b + "'";
        else if(r - l + 1 == 4)
            return "true";
    }
    else if(l == 2) {
        if(r - l + 1 == 1)
            return a + "' + " + b + "'";
        else if(r - l + 1 == 2)
            return a + "'";
        else if(r - l + 1 == 4)
            return "true";
    }
    else if(l == 3) {
        if(r - l + 1 == 1)
            return a + "' + " + b;
        else if(r - l + 1 == 2)
            return b;
        else if(r - l + 1 == 4)
            return "true";
    }

    return "true";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vi a;
    while(true){
        int temp;
        cin >> temp;
        if(temp == -1)
            break;
        a.push_back(temp);
    }

    vector<vector<int>> s(8, vector<int>(8)); // matrix of all the ones
    for(auto u : a) {
        ll row = gc[u/4]; // first two bits of u are u/4
        ll col = gc[u%4]; // last two bits of u are u%4
        s[row][col] = 1;
    }

    // copying the ones into the rest of the matrix
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            s[i][j] = s[i%4][j%4];
            if(i < 4 && j < 4)
                cout << s[i][j] << ' ';
        }
        if(i < 4)
            cout << nl;
    }
    cout << nl;

    // making the matrix a prefix sum matrix
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            s[i][j] = s[i][j] + (i > 0 ? s[i - 1][j] : 0) + (j > 0 ? s[i][j - 1] : 0) - (i > 0 && j > 0 ? s[i - 1][j - 1] : 0);
        }
    }

    // array of all possible dimensions of the K-map groups
    vector<rect> dims;
    for(int i : {1, 2, 4}) {
        for(int j : {1, 2, 4}) {
            dims.push_back(rect(i, j));
        }
    }

    vector<vector<int>> occ(4, vector<int>(4, 0));

    vector<group> grps;
    // grps will contain the coordinates of the groups in the K-map

    for(auto u : dims) {
        int dr = u.l;
        int dc = u.w;

        for(int r = 0; r < 4; ++r) {
            for(int c = 0; c < 4; ++c) {
                if(sum(r, c, r + dr - 1, c + dc - 1, s) == (dr) * (dc)) {
                    grps.push_back(group(r, c, r + dr - 1, c + dc - 1));
                    for(int i = r; i < r + dr; ++i) {
                        for(int j = c; j < c + dc; ++j) {
                            ++occ[i%4][j%4];
                        }
                    }
                }
            }
        }
    }

    sort(grps.begin(), grps.end(), [&](group left, group right) {
        return left < right;
    });

    vector<group> final_grps; // the final list of groups

    for(group u : grps) {
        bool unnecesary = 1;
        for(int i = u.x; i <= u.X; ++i) {
            for(int j = u.y; j <= u.Y; ++j) {
                if(occ[i%4][j%4] <= 1) {
                    unnecesary = 0;
                    break;
                }
            }
        }

        if(unnecesary) {
            for(int i = u.x; i <= u.X; ++i) {
                for(int j = u.y; j <= u.Y; ++j) {
                    --occ[i%4][j%4];
                }
            }
        }
        else {
            final_grps.push_back(u);
        }
    }


    string ans = "";
    for(auto u : final_grps) {
        string tmp1 = exp_pos(u.x, u.X, 1);
        string tmp2 = exp_pos(u.y, u.Y, 0);

        cout << "(" << u.x << ", " << u.y << "); (" << u.X << ", " << u.Y << ")" << " : " << tmp1 << " : " <<  tmp2 << nl;

        if(tmp1 != "true" && tmp2 != "true")
            ans += "(" + tmp1 + " + " + tmp2 + ") ";
        else if(tmp1 != "true")
            ans += "(" + tmp1 + ") ";
        else if(tmp2 != "true")
            ans += "(" + tmp2 + ") ";
    }
    cout << (ans.length() != 0 ? ans : "0") << nl;
} 
