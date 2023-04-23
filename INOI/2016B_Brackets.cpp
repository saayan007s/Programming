#include "bits/stdc++.h"
using namespace std;

#define long int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int b[n + 1]; long v[n + 1];
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];

    long dp[n + 2][n + 2] = {};

    for(int i = n - 1; i > 0; --i) {
        for(int j = i + 1; j <= n; ++j) {
            dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            for(int x = i + 1; x <= j; ++x) {
                if(b[i] + k == b[x]) {
                    long add = max((long)0, v[i] + v[x]);
                    dp[i][j] = max(dp[i][j], dp[i + 1][x - 1] + add + dp[x + 1][j]);
                }
            }
        }
    }

    cout << dp[1][n];
}
