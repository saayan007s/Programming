#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    bool grid[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            char c; cin >> c;
            grid[i][j] = (c == '.' ? 1 : 0);
        }
    }
 
    int dp[n][n] = {};
    dp[0][0] = grid[0][0];
    const int mod = 1e9 + 7;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if((i != 0 || j != 0) && grid[i][j]) {
                dp[i][j] = (i - 1 >= 0 ? dp[i - 1][j] : 0) + (j - 1 >= 0 ? dp[i][j - 1] : 0);
                if(dp[i][j] >= mod) dp[i][j] -= mod;
            }
        }
    }
 
    cout << dp[n-1][n-1];
}
