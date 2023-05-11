#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 2e5L + 1;
int n;
vector<int> adj[N];
int c[N], d[N];
int ans[N];

void dfs(int x, int p) {
    c[x] = 1;
    d[x] = 0;
    for(int y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        c[x] += c[y];
        d[x] += d[y] + c[y];
    }
}

void dfs2(int x, int p) {
    ans[x] = d[x];
    for(int y : adj[x]) {
        if(y == p) continue;
        c[x] -= c[y];
        d[x] -= (d[y] + c[y]);
        c[y] += c[x];
        d[y] += d[x] + c[x];
        dfs2(y, x);
        d[y] -= d[x] + c[x];
        c[y] -= c[x];
        d[x] += (d[y] + c[y]);
        c[x] += c[y];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }

    dfs(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
