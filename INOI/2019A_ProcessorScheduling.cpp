#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

void solve() {
    int n, m;
    cin >> n >> m;
    int q[n + 1];
    for(int i = 1; i <= n; ++i) cin >> q[i];
    pair<int, int> tmp[m + 1];
    for(int i = 1; i <= m; ++i) cin >> tmp[i].sc;
    for(int i = 1; i <= m; ++i) cin >> tmp[i].fr;
    sort(tmp + 1, tmp + m + 1);
    int p[m + 1], t[m + 1];
    for(int i = 1; i <= m; ++i) p[i] = tmp[i].sc, t[i] = tmp[i].fr;

    const int inf = 1e18L;
    int dp[n + 1][m + 1];
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[i][j] = inf;

    dp[0][0] = 0;
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= m; ++j) {
            if(i + j == 0) continue;

            int time = inf;
            if(i) {
                if(dp[i - 1][j] != inf)
                    time = min(time, dp[i - 1][j] + q[i]);
            }
            if(j) {
                if(dp[i][j - 1] != inf && dp[i][j - 1] <= t[j])
                    time = min(time, max(t[j], dp[i][j - 1] + p[j]));
            }

            dp[i][j] = time;
        }
    }

    cout << (dp[n][m] == inf ? -1 : dp[n][m]) << nl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve();
    }
}
