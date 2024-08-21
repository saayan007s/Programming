#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int main() 
{
    const int mod = 1'000'000'007;
    int n; cin >> n;
    int dp[n+1];
    dp[0] = 1;
    for(int i = 1; i <= n; ++i) {
        dp[i] = 0;
        for(int j = 1; j < 7 && i - j >= 0; ++j) {
            dp[i] += dp[i - j];
            if(dp[i] >= mod) dp[i] -= mod;
        }
    }
    cout << dp[n];
}