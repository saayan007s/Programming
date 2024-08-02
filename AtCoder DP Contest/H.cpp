#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1000'000'007;
    int H, W;
    cin >> H >> W;
    char a[H][W];
    for(int i = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j) {
            cin >> a[i][j];
        }
    }

    int dp[H + 1][W + 1] = {};
    dp[1][1] = 1;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            if(a[i - 1][j - 1] == '.') {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
                if(dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
    }
    cout << dp[H][W];
}
