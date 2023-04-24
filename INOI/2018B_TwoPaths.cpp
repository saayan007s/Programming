#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int inf = 1e18L;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int s[n + 1][m + 1] = {};
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> s[i][j];
            s[i][j] += s[i][j - 1];
            /* cout << s[i][j] << ' '; */
        }
        /* cout << nl; */
    }
    /* cout << nl; */

    int dp[n + 1][m + 1][k + 1] = {};
    int sub[n + 1][m + 1][k + 1] = {};

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            for(int x = 0; x <= k; ++x) {
                dp[i][j][x] = s[i][j];
                int add = -inf;
                if(i == 1) add = 0;
                else if(j == 1) {
                    if(x == 0) add = max(add, dp[i - 1][j][x]);
                    else add = max({add, dp[i - 1][j][x], dp[i - 1][j][x - 1]});
                }
                else if(j != 1) {
                    if(x == 0) add = max(add, dp[i - 1][j][x]);
                    else add = max({add, dp[i - 1][j][x], dp[i - 1][j][x - 1], dp[i - 1][j - 1][x - 1]});
                }
                dp[i][j][x] += add;

                add = inf;
                sub[i][j][x] = s[i][j - 1];
                if(i == 1 || j == 1) add = 0;
                else {
                    if(x == 0) add = min(add, sub[i - 1][j][x]);
                    else add = min({add, sub[i - 1][j][x], sub[i - 1][j][x - 1], sub[i - 1][j - 1][x - 1]});
                }
                sub[i][j][x] += add;
            }
        }
    }

    /* for(int i = 1; i <= n; ++i) { */
    /*     for(int j = 1; j <= m; ++j) { */
    /*         cout << dp[i][j][k] << ' '; */
    /*     } */
    /*     cout << nl; */
    /* } */
    /* cout << nl; */
    /* for(int i = 1; i <= n; ++i) { */
    /*     for(int j = 1; j <= m; ++j) { */
    /*         cout << sub[i][j][k] << ' '; */
    /*     } */
    /*     cout << nl; */
    /* } */
    /* cout << nl; */
    int res = -inf;
    for(int l = 1; l <= m; ++l) {
        for(int r = l + k + 1; r <= m; ++r) {
            res = max(res, dp[n][r][k] - sub[n][l][k]);
        }
    }
    cout << res << nl;
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

