#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int64_t W;
    cin >> N >> W;

    int64_t w[N];
    int v[N];
    for(int i = 0; i < N; ++i) {
        cin >> w[i] >> v[i];
    }

    int V = 0;
    for(int val : v) V += val;

    int64_t dp[V + 1];
    for(int i = 0; i <= V; ++i) dp[i] = W + 1;
    dp[0] = 0;

    for(int i = 0; i < N; ++i) {
        for(int j = V; j >= 0; --j) {
            if(dp[j] <= W && dp[j] + w[i] <= W && j + v[i] <= V && dp[j] + w[i] < dp[j + v[i]]) {
                dp[j + v[i]] = dp[j] + w[i];
            }
        }
    }

    for(int j = V; j >= 0; --j) {
        if(dp[j] <= W) {
            cout << j;
            return 0;
        }
    }
}
