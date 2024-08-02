#include "bits/stdc++.h"
using namespace std;

const int mod = 1'000'000'007;
const int base = 10;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string k;
    int d, n, res;
    cin >> k >> d;

    // finding digits
    n = k.size();
    int dig[n];
    for(int i = 0; i < n; ++i) dig[i] = k[i] - '0';

    int dp[n][base][d][2] = {};

    for(int i = 0; i <= dig[0]; ++i) {
        dp[0][i][i%d][(i < dig[0] ? 1 : 0)] = 1;
    }
    for(int i = 0; i < n - 1; ++i) {
        for(int j = 0; j < base; ++j) {
            for(int x = 0; x < d; ++x) {
                for(int f = 0; f < 2; ++f) {
                    int add = dp[i][j][x][f];
                    for(int nex = 0; nex < (f ? base : dig[i + 1] + 1); ++nex) {
                        int g = (!f && nex >= dig[i + 1] ? 0 : 1);
                        int rem = (x + nex) % d;
                        dp[i + 1][nex][rem][g] += add;
                        if(dp[i + 1][nex][rem][g] >= mod) dp[i + 1][nex][rem][g] -= mod;
                    }
                }
            }
        }
    }

    res = 0;
    for(int j = 0; j < base; ++j) {
        for(int f = 0; f < 2; ++f) {
            res += dp[n - 1][j][0][f];
            if(res >= mod) res -= mod;
        }
    }
    res -= 1;
    if(res < 0) res += mod;
    cout << res;
}
