#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin >> n;
    int dp[n+1];
    dp[0] = 0;
 
    for(int i = 1; i <= n; ++i) {
        int j = i;
        dp[i] = INT_MAX;
        while(j != 0) {
            int digit = j%10;
            if(digit) dp[i] = min(dp[i - digit] + 1, dp[i]);
            j /= 10;
        }
    }
 
    cout << dp[n];
}
