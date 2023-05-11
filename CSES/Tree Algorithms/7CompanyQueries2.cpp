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
        int a, b; cin >> a >> b;
        if(a == b) {
            cout << a << nl;
            continue;
        }
        if(depth[a] > depth[b]) swap(a, b);
        int diff = depth[b] - depth[a];
        for(int j = logn - 1; j >= 0; --j) {
            if(diff & (1ll << j)) b = par[b][j];
        }
        if(a == b) {
            cout << a << nl;
            continue;
        }
        for(int j = logn - 1; j >= 0; --j) {
            if(par[a][j] != par[b][j]) {
                a = par[a][j];
                b = par[b][j];
            }
        }
        cout << par[a][0] << nl;
    }
}
