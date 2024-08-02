#include "bits/stdc++.h"
using namespace std;

const int mod = 1'000'000'007;

int add(int x, int y) {
    if ( ((x += y) %= mod) < 0) x += mod;
    return x;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;
    s = " " + s;

    int dp[n + 1][n + 1] = {};
    dp[1][1] = 1;

    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            dp[i - 1][j] += dp[i - 1][j - 1];
            if(dp[i - 1][j] >= mod) dp[i - 1][j] -= mod;
        }

        for(int j = 1; j <= i; ++j) {
            if(s[i - 1] == '<') {
                dp[i][j] += dp[i - 1][j - 1];
                if(dp[i][j] >= mod) dp[i][j] -= mod;
            }
            else {
                dp[i][j] += dp[i - 1][i - 1] - dp[i - 1][j - 1];
                dp[i][j] %= mod;
                if(dp[i][j] < 0) dp[i][j] += mod;
            }
        }
    }
    int ans = 0;
    for(int j = 1; j <= n; ++j) {
        ans += dp[n][j];
        if(ans >= mod) ans -= mod;
    }
    cout << ans;
}
