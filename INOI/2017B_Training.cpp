#include "bits/stdc++.h"
using namespace std;

#define long int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

long train(int x) {
    int sum = 0, store = x;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return (store + sum*sum*sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    long s[n + 1];
    cin >> s[0];
    for(int i = 1; i <= n; ++i) s[i] = train(s[i - 1]);
    int e[n + 1];
    for(int i = 1; i <= n; ++i) cin >> e[i];

    long dp[n + 1][n + 1] = {};
    dp[1][0] = s[0] * e[1];
    long res = 0;

    for(int i = 2; i <= n; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
            if(i - 1 >= j) dp[i][j] = max(dp[i][j], dp[i - 1][j] + s[j]*e[i]);
            if(i == n) res = max(res, dp[i][j]);
        }
    }

    cout << res;
}
