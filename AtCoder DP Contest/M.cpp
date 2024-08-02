#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1'000'000'007;
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int &i : a) cin >> i;

    int dp[n + 1][k + 1] = {};
    dp[0][0] = 1;

    int pf[k + 1];
    for(int i = 1; i <= n; ++i) {
        pf[0] = dp[i - 1][0];
        for(int j = 1; j <= k; ++j) {
            pf[j] = pf[j - 1] + dp[i - 1][j];
            if(pf[j] >= mod) pf[j] -= mod;
        }

        for(int j = 0; j <= k; ++j) {
            dp[i][j] = pf[j] - (j - a[i - 1] - 1 >= 0 ? pf[j - a[i - 1] - 1] : 0);
            if(dp[i][j] < 0) dp[i][j] += mod;
            if(dp[i][j] >= mod) dp[i][j] -= mod;
        }
    }
    cout << dp[n][k];
}
