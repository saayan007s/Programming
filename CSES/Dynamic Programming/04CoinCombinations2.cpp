#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const int mod = 1e9 + 7;

	int n, x;
    cin >> n >> x;
 
    int c[n];
    int dp[x+1] = {};
 
    for(int& i : c) cin >> i;

    dp[0] = 1;
    for(int v : c) {
        for(int i = v; i <= x; ++i) {
            if( (dp[i] += dp[i - v]) >= mod) dp[i] -= mod;
        }
    }
 
    cout << dp[x];
}