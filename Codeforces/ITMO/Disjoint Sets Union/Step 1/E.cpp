#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using vi = vector<int>;
using vl = vector<long long>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb emplace_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const ll mxn = 2e5L + 1;
const ll mxm = 4e5L + 1;
ll n, m;
ll adj[mxn][2] = {};
ll rem[mxm][2] = {};
ll tt[mxn] = {};

struct UFDS {
    vl sz;
    vl lnk;
    // vl tt;

    UFDS(ll N) {
        sz = vl(N, 1);
        lnk = vl(N);
        iota(all(lnk), 0);
        // tt = vl(N, -1);
    }

    ll find(ll a) {
        if(a == lnk[a]) {
            return a;
        }

        find(lnk[a]);
        tt[a] = max(tt[a], tt[lnk[a]]);
        return lnk[a] = find(lnk[a]);
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    void unite(ll a, ll b, ll t) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(same(a, 1ll)) {
            swap(a, b);
        }

        if(!same(a, 1ll) && same(b, 1ll)) {
            tt[a] = t;
        }

        lnk[a] = b;
        sz[b] += sz[a];

        return;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fur(i, 1, n) {
        fur(j, 0, 1) {
            cin >> adj[i][j];
            // if(adj[i][j] != -1) 
                // cout << i << ' ' << adj[i][j] << nl;
        }
    }
    // cout << nl;

    bool st[n + 1][2] = {};
    fur(i, 1, m) {
        ll p, h;
        cin >> p >> h;
        --h;
        rem[i][0] = p;
        rem[i][1] = adj[p][h];
        st[p][h] = 1;
        // cout << rem[i][0] << ' ' << rem[i][1] << nl;
    }

    fur(i, 0, n) {
        tt[i] = -1;
    }

    UFDS uf(n + 1);
    fur(i, 1, n) {
        fur(j, 0, 1) {
            if(!st[i][j] && adj[i][j] != -1) {
                uf.unite(i, adj[i][j], -1);
                // cout << i << ' ' << adj[i][j] << nl;
            }
        }
    }
    // cout << nl;

    ruf(i, m, 1) {
        // if(!uf.same(rem[i][0], rem[i][1])) {
            // if(uf.same(rem[i][0], 1ll)) {
                // swap(rem[i][0], rem[i][1]);
            // }
// 
            // if(!uf.same(rem[i][0], 1ll)) {
                // fur(j, 1, n) {
                    // if(uf.same(j, rem[i][0])) {
                        // tt[j] = i - 1;
                    // }
                // } 
            // }
// 
            // uf.unite(rem[i][0], rem[i][1], i-1);
        // }
        uf.unite(rem[i][0], rem[i][1], i - 1);
    }

    fur(i, 1, n) {
        uf.find(i);
        cout << tt[i] << nl;
    }
    // cout << nl;
}
