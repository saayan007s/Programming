#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int64_t a[n];
    for(int64_t &i : a) cin >> i;

    const int64_t inf = 1'000'000'000'000'000; // 1e15
    int64_t dp[n][n];
    int64_t sum;
    for(int i = n - 1; i >= 0; --i) {
        dp[i][i] = 0;
        sum = a[i];
        for(int j = i + 1; j < n; ++j) {
            sum += a[j];
            dp[i][j] = inf;
            for(int k = i; k < j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum);
            }
        }
    }
    cout << dp[0][n - 1];
}
