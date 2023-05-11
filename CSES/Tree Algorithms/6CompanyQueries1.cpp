#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"
 
const int N = 2e5L + 5;
const int logn = 20;
int n, q;
vector<int> adj[N];
int depth[N];
int par[N][logn];
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> q;
    par[1][0] = 1;
    depth[1] = 0;
    for(int i = 2; i <= n; ++i) {
        cin >> par[i][0];
        depth[i] = depth[par[i][0]] + 1;
    }
    for(int j = 1; j < logn; ++j) {
        for(int i = 1; i <= n; ++i) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
 
    for(int tt = 1; tt <= q; ++tt) {
        int x, k; cin >> x >> k;
        if(depth[x] < k) {cout << -1 <<'\n'; continue;}
        for(int j = logn - 1; j >= 0; --j) {
            if(k & (1ll << j))
                x = par[x][j];
        }
        cout << x << nl;
    }
}
