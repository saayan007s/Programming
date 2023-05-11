#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    vector<int> adj[n + 1];
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }

    int dist[n + 1]; int x = 1, mx = 0;
    bool vis[n + 1] = {};
    dist[0] = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        dist[u] = dist[p] + 1;
        vis[u] = 1;
        if(dist[u] > mx) {
            mx = dist[u];
            x = u;
        }
        for(int v : adj[u]) {
            if(!vis[v])
                dfs(v, u);
        }
    };

    dfs(1, 0);
    fill(vis, vis + n + 1, 0);
    dfs(x, 0);
    cout << --mx << nl;
}
