#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int64_t a[n];
    for(auto &i : a) cin >> i;

    int64_t dp[n][n];
    for(int i = n - 1; i >= 0; --i) {
        dp[i][i] = a[i];
        for(int j = i + 1; j < n; ++j) {
            dp[i][j] = max(a[i] - dp[i + 1][j], a[j] - dp[i][j - 1]);
        }
    }
    cout << dp[0][n - 1];
}
