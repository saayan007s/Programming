#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int w[n], s[n]; int64_t v[n];
    for(int i = 0; i < n; ++i) {
        cin >> w[i] >> s[i] >> v[i];
    }

    int order[n];
    iota(order, order + n, 0);
    sort(order, order + n, [&](int i, int j) {
        return s[i] - w[j] > s[j] - w[i];      
    });

    const int V = 10'001;
    int64_t dp[V];
    for(int i = 0; i < V; ++i) dp[i] = -1;

    for(int r = 0; r < n; ++r) {
        int i = order[r];
        for(int j = 0; j < V; ++j) {
            int k = min(j - w[i], s[i]);
            if(k >= 0 && dp[k] < dp[j] + v[i]) {
                dp[k] = dp[j] + v[i];
            }
        }
        if(dp[s[i]] < v[i]) {
            dp[s[i]] = v[i];
        }
    }

    cout << *max_element(dp, dp + V);
}
