#include "bits/stdc++.h"
using namespace std;

const int mod = 1'000'000'007;

void dfs(int x, int p, int dp[][2], vector<int> adj[]) {
    dp[x][0] = 1, dp[x][1] = 1;
    for(int y : adj[x]) if(y != p) {
        dfs(y, x, dp, adj);
        dp[x][0] = (1LL * dp[x][0] * (dp[y][0] + dp[y][1])) % mod;
        dp[x][1] = (1LL * dp[x][1] * dp[y][0]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> adj[n];
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y; --x, --y;
        adj[x].emplace_back(y);
        adj[y].emplace_back(x);
    }

    int dp[n][2] = {};
    dfs(0, -1, dp, adj);

    int res = dp[0][0] + dp[0][1];
    if(res >= mod) res -= mod;
    cout << res;
}
