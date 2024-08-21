#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int mod = 1e9 + 7;
 
    int n, m;
	cin >> n >> m;
    int x[n + 1];
    for(int i = 1; i <= n; ++i) cin >> x[i];

    int dp[n + 1][m + 1] = {};
    if(x[1] > 0) dp[1][x[1]] = 1;
    else for(int i = 1; i <= m; ++i) dp[1][i] = 1;
 
    for(int i = 2; i <= n; ++i) {
        if(x[i] > 0) {
            dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i]]) % mod;
            if(x[i] > 1)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] - 1]) % mod;
            if(x[i] + 1 <= m)
                dp[i][x[i]] = (dp[i][x[i]] + dp[i - 1][x[i] + 1]) % mod;
        }
        else {
            for(int j = 1; j <= m; ++j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if(j > 1)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if(j + 1 <= m)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
    }
 
    int ans = 0;
    for(int j = 1; j <= m; ++j) ans = (ans + dp[n][j]) % mod;
    cout << ans;
}
