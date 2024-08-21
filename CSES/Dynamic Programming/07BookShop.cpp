#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	int n,x;
	cin >> n >> x;
    int wt[n], vl[n];
    for(int i = 0; i < n; ++i) cin >> wt[i];
    for(int i = 0; i < n; ++i) cin >> vl[i];
 
	int dp[x+1] = {};
    for(int i = 0; i < n; ++i) {
        for(int j = x; j >= wt[i]; --j) {
            dp[j] = max(dp[j], dp[j - wt[i]] + vl[i]);
		}
	}
 
	cout << dp[x];
}
