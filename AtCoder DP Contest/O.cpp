#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int mod = 1'000'000'007;

    int n;
    cin >> n;
    bool a[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }

    int N = (1 << n);
    int dp[N][n] = {};
    // dp[mask][i] = get men in mask married in some order to women 0, 1, ..; where man i is married last

    for(int mask = 0; mask < N; ++mask) {
        int c = 0;
        for(int i = 0; i < n; ++i) if((mask >> i) & 1) ++c;

        for(int i = 0; i < n; ++i) {
            if(((mask >> i) & 1) && a[i][c - 1]) {
                if(c == 1) {
                    dp[mask][i] = 1;
                }
                else {
                    int sub = mask ^ (1 << i);
                    for(int j = 0; j < n; ++j) {
                        if((sub >> j) & 1) {
                            dp[mask][i] += dp[sub][j];
                            if(dp[mask][i] >= mod) dp[mask][i] -= mod;
                        }
                    }
                }
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; ++i) {
        res += dp[N - 1][i];
        if(res >= mod) res -= mod;
    }
    cout << res;
}
