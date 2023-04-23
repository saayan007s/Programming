#include "bits/stdc++.h"
using namespace std;

#define long int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    if(n <= 2) {
        cout << 2 % m;
        return 0;
    }

    int dp[n + 1];
    dp[1] = dp[2] = 2%m;
    int pow = 4%m;
    for(int i = 3; i <= n; ++i) {
        pow = (2 * pow) % m;
        dp[i] = pow % m;
        for(int j = 1; j*j <= i; ++j) {
            if(i % j == 0) {
                dp[i] = ((dp[i] - dp[j]) % m + m) % m;
                if(j != 1 && j * j != i)
                    dp[i] = ((dp[i] - dp[i/j]) % m + m) % m;
            }
        }
    }
    cout << dp[n];
}
