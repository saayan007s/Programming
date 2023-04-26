#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

#define inf 1000000000000000LL

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];
    pair<int, pair<int, int>> b[m + 1];
    for(int i = 1; i <= m; ++i) cin >> b[i].fr >> b[i].sc.fr >> b[i].sc.sc;

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    int cost[m + 1][n + 1] = {};
    for(int j = 1; j <= m; ++j) {
        for(int i = 1; i <= n; ++i)
            cost[j][i] = cost[j][i - 1] + abs(a[i] - b[j].fr);
    }
    int dp[m + 1][n + 1];
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= m; ++j) dp[j][i] = inf;
    dp[0][0] = 0;

    for(int i = 1; i <= m; ++i) {
        deque<int> dq;
        int opt[n + 1];
        for(int j = 0; j <= n; ++j) opt[j] = dp[i - 1][j] - cost[i][j];
        for(int j = 0; j <= n; ++j) {
            int l = j - b[i].sc.sc, r = j - b[i].sc.fr;
            if(r >= 0) {
                while(!dq.empty() && dq.back() > opt[r]) dq.pop_back();
                dq.push_back(opt[r]);
            }
            if(l > 0) {
                if(opt[l - 1] == dq.front()) dq.pop_front();
            }
            if(!dq.empty()) dp[i][j] = min(dp[i][j], dq.front() + cost[i][j]);
        }
    }
    if(dp[m][n] >= inf) cout << -1;
    else cout << dp[m][n];
}
