#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	int n;
    cin >> n;
    int x[n + 1];
    int64_t dp[n + 1][n + 1] = {};
 
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
 
    for(int i = n; i > 0; --i) {
        dp[i][i] = x[i];
        for(int j = i + 1; j <= n; ++j) {
            dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
        }
    }
 
    int64_t tot = 0;
    for(int i = 1; i <= n; ++i) tot += x[i];
    int64_t ans = (dp[1][n] + tot) / 2;
    cout << ans;
}
