#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int n,x;
    cin >> n >> x;
    int c[n];

    int dp[x+1];
    for(int& i : c) cin >> i;
 
    dp[0] = 0;
    for(int i = 1; i <= x; ++i) {
        dp[i] = INT_MAX;
        for(int v : c) {
            if(i - v >= 0 && dp[i - v] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - v] + 1);
            }
        }
    }

    cout << (dp[x] == INT_MAX ? -1 : dp[x]);
}
