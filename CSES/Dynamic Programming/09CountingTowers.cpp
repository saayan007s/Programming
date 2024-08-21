#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int mod = 1e9 + 7;
    const int N = 1'000'000;
 
    int dp[N + 1];
    int s[N + 1];
 
    dp[0] = s[0] = 1;

    dp[1] = 2;
    s[1] = s[0] + dp[1];

    for(int i = 2; i <= N; ++i) {
        dp[i] = (5 * 1LL * dp[i - 1] - 2 * 1LL * s[i - 2]) % mod;
        if(dp[i] < 0) dp[i] += mod;
        s[i] = (s[i - 1] + dp[i]);
        if(s[i] >= mod) s[i] -= mod;
    }
 
    int t; cin >> t;
    for(int i = 0; i < t; ++i) {
        int n; cin >> n;
        cout << dp[n] << (i == t - 1 ? "" : "\n");
    }
}
