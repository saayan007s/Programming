#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int dp[n + 1][3] = {};
    for(int i = 1; i <= n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> dp[i][j];
        }
        dp[i][0] += max(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += max(dp[i - 1][0], dp[i - 1][1]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]});
}
