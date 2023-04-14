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

int sum(ll r, ll c, ll rr, ll cc, const vector<vector<int>>& s)
{
    return s[rr][cc] - (r > 0 ? s[r - 1][cc] : 0) - (c > 0 ? s[rr][c - 1] : 0) + (r > 0 && c > 0 ? s[r - 1][c - 1] : 0);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vi a;
    while(true){
        int temp;
        cin >> temp;
        if(temp == -1)
            break;
        a.push_back(temp);
    }

    vector<vector<int>> s(8, vector<int>(8)); // prefix sum
    for(auto u : a) {
        ll row = gc[u/4];
        ll col = gc[u%4];
        s[row][col] = 1;
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 4; ++j) {
            cout << s[i][j] << ' ';
        }
        cout << nl;
    }

    // copying the values
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            s[i][j] = s[i%4][j%4];
        }
    }

    // keeping the values in a set
    set<pair<int, int>> ones;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(s[i][j] == 1)
                ones.insert({i, j});
        }
    }

    // creating the prefix sum array
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            s[i][j] = s[i][j] + (i > 0 ? s[i - 1][j] : 0) + (j > 0 ? s[i][j - 1] : 0) - (i > 0 && j > 0 ? s[i - 1][j - 1] : 0);
        }
    }

    vector<rect> dims;
    for(int i : {1, 2, 4}) {
        for(int j : {1, 2, 4}) {
            dims.push_back(rect(i, j));
        }
    }
    sort(dims.rbegin(), dims.rend());

    vector<pair<pair<int, int>, pair<int, int>>> grps;    
    for(auto u : dims) {
        int dr = u.l;
        int dc = u.w;
        // cout << dr << ' ' << dc << nl;
        for(int r = 0; r < 4; ++r) {
            for(int c = 0; c < 4; ++c) {
                if(sum(r, c, r + dr - 1, c + dc - 1, s) == (dr) * (dc)) {


                    // cout << "(" << r << ", " << c << "); (" << r + dr - 1 << ", " << c + dc - 1 << ")" << nl;
                    auto ptr = ones.lower_bound({r, c});
                    if(ptr == ones.end())
                        continue;
                    auto temp = *ptr;
                    if(r == 1 && c == 2 && dr == 2 && dc == 2){
                        cout << "hello" << nl;
                        for(auto u : ones)
                            if(u.fr < 4 && u.sc < 4)
                                cout << u.fr << ' ' << u.sc << nl;
                        cout << nl;
                        cout << temp.fr << ' ' << temp.sc << nl;
                        cout << (mp(r, c) >= temp && temp <= mp(r + dr, c + dc)) << nl;
                        cout << nl;
                        
                    }

                    while(ptr != ones.end() && *ptr > mp(r + dr, c + dc))
                        ++ptr;
                    if(ptr == ones.end())
                        continue;
                    temp = *ptr;

                    if(temp <= mp(r + dr, c + dc)) {
                        grps.push_back({{r, c}, {r + dr - 1, c + dc - 1}});

                        for(int i = r; i < r + dr; ++i) {
                            for(int j = c; j < c + dc; ++j) {
                                for(int k : {0, 4})
                                    for(int l : {0, 4})
                                        ones.erase({i%4 + k, j%4 + l});
                            }
                        }
                    }
                }
            }
        }
    }

    for(auto u : grps)
    {
        cout << "(" << u.fr.fr << ", " << u.fr.sc << "); (" << u.sc.fr << ", " << u.sc.sc << ")" << nl;
    }

} 
