#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, W;
    cin >> N >> W;

    int w[N];
    int64_t v[N];
    for(int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    int64_t dp[W + 1] = {};
    for(int i = 0; i < N; ++i) {
        for(int j = W; j >= 0; --j) {
            if(j + w[i] <= W && dp[j] + v[i] > dp[j + w[i]]) {
                dp[j + w[i]] = dp[j] + v[i];
            }
        }
    }

    cout << dp[W];
}
