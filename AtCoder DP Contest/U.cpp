#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int64_t a[n][n];
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> a[i][j];

    int N = (1 << n);
    int64_t cost[N];
    cost[0] = 0;

    for(int m = 1; m < N; ++m) {
        cost[m] = 0;
        for(int i = 0; i < n; ++i) {
            if((m >> i) & 1) {
                cost[m] = cost[m ^ (1 << i)];
                for(int j = i + 1; j < n; ++j) {
                    if((m >> j) & 1) {
                        cost[m] += a[i][j];
                    }
                }
                break;
            }
        }
    }

    int b[n] = {};
    int64_t dp[N];

    dp[0] = 0;
    for(int m = 1; m < N; ++m) {
        int bi = 0, f = -1;
        dp[m] = -1e15;
        for(int i = 0; i < n; ++i) {
            if(!(1 & (m >> i))) continue;
            if(f == -1) f = i;
            else b[bi++] = i;
        }
        
        for(int tmp = 0; tmp < (1 << bi); ++tmp) {
            int k = (1 << f);
            for(int i = 0; i < bi; ++i) {
                if(!(1 & (tmp >> i))) continue;
                k = k | (1 << b[i]);
            }
            dp[m] = max(dp[m], cost[k] + dp[m^k]);
        }
    }

    cout << dp[N - 1];
}
