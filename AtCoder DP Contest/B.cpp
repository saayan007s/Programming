#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int h[n];
    for(int i = 0; i < n; ++i) cin >> h[i];

    const int inf = INT_MAX;
    int dp[n];
    dp[0] = 0;
    for(int i = 1; i < n; ++i) {
        dp[i] = inf;
        for(int j = 1; j <= k && j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
        }
    }
    cout << dp[n - 1];
}
