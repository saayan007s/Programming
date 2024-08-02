#include "bits/stdc++.h"
using namespace std;

const int N = 100'001;
int n, mod;
vector<int> adj[N];
int dp[N], dp2[N];
int pref[N], suf[N];
int ans[N];

int add(int x, int y) {
    return ((x + y) % mod + mod) % mod; 
}

int mul(int x, int y) {
    return ((1LL * x * y) % mod + mod) % mod;
}

void dfs2(int x, int p) {
    if(x == 1) dp2[x] = 1;
    int k = adj[x].size();
    for(int i = 0; i < k; ++i) {
        int y = adj[x][i];
        if(y == p) pref[i] = (i == 0 ? 1 : pref[i - 1]);
        else pref[i] = (i == 0 ? dp[y] : mul(dp[y], pref[i - 1]));
    }
    for(int i = k - 1; i >= 0; --i) {
        int y = adj[x][i];
        if(y == p) suf[i] = (i == k - 1 ? 1 : suf[i + 1]);
        else suf[i] = (i == k - 1 ? dp[y] : mul(dp[y], suf[i + 1]));
    }
    for(int i = 0; i < k; ++i) {
        int y = adj[x][i];
        if(y == p) continue;
        else dp2[y] = add(1, mul(dp2[x], mul(i == 0 ? 1 : pref[i - 1], i == k - 1 ? 1 : suf[i + 1])));
    }
    for(auto y : adj[x]) if(y != p) {
        dfs2(y, x);    
    }
}

void dfs(int x, int p) {
    dp[x] = 1;
    for(auto y : adj[x]) if(y != p) {
        dfs(y, x);    
        dp[x] = mul(dp[x], dp[y]);
    }
    dp[x] = add(dp[x], 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> mod;
    for(int i = 1; i < n; ++i) {
        int x, y; cin >> x >> y;
        adj[x].emplace_back(y); adj[y].emplace_back(x);
    }

    dfs(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) {
        cout << mul(dp2[i], add(dp[i], -1)) << '\n';
    }
}
