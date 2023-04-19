#include "bits/stdc++.h"
using namespace std;

using ll = long long;
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define nl "\n"

const ll N = 1e5L + 1, inf = 1e18;
ll n, k;
ll a[N];
ll wt[N], sum[N];
ll dp[N][2];

ll C(ll l, ll r) {
    return (wt[r] - wt[l - 1]) - l * (sum[r] - sum[l - 1]);
}

void dnc(ll lvl, ll prv, ll l, ll r, ll optl, ll optr) {
    if(l > r) return;
    ll d = (l + r) / 2;
    pair<ll, ll> best = {inf, -1};
    for(ll i = optl; i <= min(d, optr); ++i) {
        best = min(best, {dp[i - 1][prv] + C(i, d), i});
    }
    dp[d][lvl] = best.fr;
    ll opt = best.sc;
    dnc(lvl, prv, l, d - 1, optl, opt);
    dnc(lvl, prv, d + 1, r, opt, optr);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    wt[0] = sum[0] = 0;
    for(ll i = 1; i <= n; ++i) {
        wt[i] = wt[i - 1] + i*a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    for(ll i = 1; i <= n; ++i)
        dp[i][0] = inf;
    dp[0][0] = 0;

    for(ll j = 1; j <= k; ++j) {
        dnc(j&1, 1 - (j&1), 1, n, 1, n);
        dp[0][j&1] = inf;
    }

    cout << dp[n][k&1] << nl;
}
