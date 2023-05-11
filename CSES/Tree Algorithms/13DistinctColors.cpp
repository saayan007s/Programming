#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
const char nl = '\n';

const int N = 2e5L + 1;
int n;
vector<int> adj[N];
set<int> col[N];
int ans[N];
int c[N];

void dfs(int x, int p) {
    col[x].insert(c[x]);
    for(int y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        if(col[x].size() < col[y].size()) swap(col[x], col[y]);
        for(int z : col[y]) col[x].insert(z);
    }
    ans[x] = col[x].size();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    map<int, bool> m; map<int, int> comp;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i];
        m[c[i]] = 1;
    }

    int j = 1;
    for(auto u : m) {
        if(u.sc) comp[u.fr] = j++;
    }
    for(int i = 1; i <= n; ++i) {
        c[i] = comp[c[i]];
    }

    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
