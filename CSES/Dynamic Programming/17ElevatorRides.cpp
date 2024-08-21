#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    int w[n];
    for(int &i : w) cin >> i;
    
    int N = 1 << n;
    pair<int, int64_t> dp[N];
    dp[0] = make_pair(1, 0LL);
    
    for(int i = 1; i < N; ++i) {
        dp[i] = make_pair(n + 1, 0LL);
        for(int j = 0; j < n; ++j) if((i >> j) & 1) {
            pair<int, int64_t> opt = dp[i ^ (1 << j)];
            if(opt.second + w[j] > x) {
                opt.first++;
                opt.second = 0;
            }
            opt.second += w[j]; 
            dp[i] = min(dp[i], opt);
        }
    }
    cout << dp[N - 1].first;
}
