#include "bits/stdc++.h"
using namespace std;

#define long long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a[n + 1], dp[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = INT_MIN;
    }

    if(n == 1) {
        cout << 0;
        return 0;
    }
    
    // forward phase
    dp[k] = 0;
    for(int i = k + 1; i <= n; ++i) {
        if(i == k + 1) dp[i] = a[i];
        else dp[i] = a[i] + max(dp[i - 1], dp[i - 2]);
    }

    // backward phase
    for(int i = n - 1; i > 0; --i) {
        if(i == n - 1) dp[i] = max(dp[i], dp[i + 1] + a[i]);
        else dp[i] = max({dp[i], dp[i + 1] + a[i], dp[i + 2] + a[i]});
    }

    cout << dp[1];
}
