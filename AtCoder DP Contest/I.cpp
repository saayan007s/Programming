#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    double p[n];
    for(double& x : p) cin >> x;

    double dp[n + 1][n + 1] = {}; // dp[i][j] = probability of getting j heads from i tosses
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
            // the i-th toss is either a heads (probability p[i - 1]) or a tails (1 - p[i - 1])
            dp[i][j] = (p[i - 1] * dp[i - 1][j - 1]) + (1 - p[i - 1]) * (dp[i - 1][j]);
        }
    }

    double ans = 0;
    for(int j = (n + 1) / 2; j <= n; ++j) ans += dp[n][j];
    cout << setprecision(20) << ans;
}
