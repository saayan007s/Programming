#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int inf = LLONG_MAX;
const int N = 501;
int n, k;
int a[N];
int dp[N][2];

inline int cost(int l, int r) {
    return (a[r] - a[l - 1]) * (r - (l - 1) - (a[r] - a[l - 1]));
}

void dnc(int lvl, int prv, int l, int r, int optl, int optr) {
    if(l > r) return;
    int d = (l + r) / 2;
    dp[d][lvl] = inf;
    int opt = -1;
    for(int i = max(1LL, optl); i <= min(d, optr); ++i) {
        if(dp[i - 1][prv] != inf && dp[d][lvl] > dp[i - 1][prv] + cost(i, d)) {
            dp[d][lvl] = dp[i - 1][prv] + cost(i, d);
            opt = i;
        }
    }

    dnc(lvl, prv, l, d - 1, optl, opt);
    dnc(lvl, prv, d + 1, r, opt, optr);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    a[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    for(int i = 1; i <= n; ++i)
        dp[i][0] = inf;
    dp[0][0] = 0;

    for(int j = 1; j <= k; ++j) {
        if(j != 1) dp[1 - j&1][0] = inf;
        dnc(j&1, 1 - j&1, 1, n, 1, n);
    }

    cout << dp[n][k&1];
}
