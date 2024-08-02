#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    int deg[n + 1] = {};
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++deg[v];
    }

    int order[n + 1];
    iota(order, order + n + 1, 0);
    sort(order + 1, order + n + 1, [&] (int left, int right) {
        return deg[left] < deg[right];
    });

    vector<int> tps;
    queue<int> q;

    for(int i = 1; i <= n; ++i)
        if(deg[i] == 0)
            q.push(i);

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        tps.push_back(a);

        for(auto b : adj[a]) {
            if(--deg[b] == 0)
                q.push(b);
        }
    }

    int dp[n + 1] = {};
    for(auto u : tps) {
        for(auto v : adj[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    cout << *max_element(dp, dp + n + 1);
}
