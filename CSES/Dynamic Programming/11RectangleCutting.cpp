#include <bits/stdc++.h>
using namespace std;
 
int main() {   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    const int n = 500;
    int dp[n + 1][n + 1] = {};
 
    dp[1][1] = 0;
 
    for(int i = 1; i <= n; ++i) {
 
        for(int j = 1; j < i; ++j) dp[i][j] = dp[j][i];
 
        dp[i][i] = 0;
 
        for(int j = i + 1; j <= n; ++j) {
            dp[i][j] = dp[ min(i,j-i) ][ max(i,j-i) ] + 1;
 
            for(int k = 1; k <= i; ++k) {
                dp[i][j] = min(dp[i][j], dp[ min(i,k) ][ max(i,k) ] + dp[ min(i,j-k) ][ max(i,j-k) ] + 1);
                dp[i][j] = min(dp[i][j], dp[ min(k,j) ][ max(k,j) ] + dp[ min(i-k,j) ][ max(i-k,j) ] + 1);
            }
 
        }
    }
    int a, b;
    cin >> a >> b;
    cout << dp[a][b];
}
