#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int inf = 1'000'000'001;

    int n;
    cin >> n;
    int h[n + 1];
    int64_t a[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    int m = 1; while(m < n + 1) m *= 2;
    int64_t ST[2*m] = {};
    
    auto qry = [&](int l, int r) -> int64_t {
        int64_t ret = 0;
        for(l += m, r += m; l <= r; l /= 2, r /= 2) {
            if(l % 2 == 1) ret = max(ret, ST[l++]);
            if(r % 2 == 0) ret = max(ret, ST[r--]);
        }
        return ret;
    };

    auto mod = [&](int i, int64_t v) {
        for(i += m; i > 0; i /= 2) {
            ST[i] = max(ST[i], v);
        }
    };

    int64_t dp[n + 1] = {};
    for(int i = 1; i <= n; ++i) {
        dp[i] = qry(0, h[i] - 1) + a[i];
        mod(h[i], dp[i]);
    }
    cout << *max_element(dp, dp + n + 1);
}
