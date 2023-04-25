#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 1e5L + 1;
vector<int> adj[N];
bool vis[N];
int mn, mx, sz, ans;

void dfs(int x) {
    if(vis[x]) return;
    vis[x] = 1;
    mn = min(mn, x);
    mx = max(mx, x);
    ++sz;
    for(int y : adj[x])
        if(!vis[y])
            dfs(y);
}

void dfs2(int x, int wt) {
    if(vis[x]) return;
    vis[x] = 1;
    ans += wt;
    for(int y : adj[x]) 
        if(!vis[y])
            dfs2(y, wt + 1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        adj[i].clear();
        vis[i] = 0;
    }

    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }

    vector<int> odd, eve;
    for(int i = 1; i <= n; ++i) {
        if(vis[i]) continue;
        mx = 0, mn = N, sz = 0;
        dfs(i);
        if(sz & 1) odd.eb(mx);
        else eve.eb(mn);
    }

    for(int i = 1; i <= n; ++i) vis[i] = 0;

    ans = 0;
    for(int u : eve) 
        if(!vis[u]) dfs2(u, 1);
    cout << ans << ' ';
    ans = 0;
    for(int u : odd) 
        if(!vis[u]) dfs2(u, 1);
    cout << ans << ' ';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve();
        cout << nl;
    }
}

