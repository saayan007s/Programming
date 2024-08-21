#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    const int mod = 1e9 + 7;
 
	int n;
    cin >> n;
    int target = n*(n+1)/2;

    if(target%2 != 0) {
        cout << 0;
        return 0;
    }
    target /= 2;
 
    int dp[n + 1][target + 1] = {};
    dp[0][0] = dp[1][0] = dp[1][1] = 1;
 
    for(int i = 2; i < n; ++i) {
        dp[i][0] = 1;
        for(int j = 1; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];
            if(j - i >= 0) {
                dp[i][j] += dp[i-1][j-i];
                if(dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
    }
    cout << dp[n - 1][target];
}
