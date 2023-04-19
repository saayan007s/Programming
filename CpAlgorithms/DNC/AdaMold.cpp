#include "bits/stdc++.h"
using namespace std;

using ll = long long;
#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define nl "\n"
#define fur(i, a, b) for(ll i = a; i <= (ll) b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll) b; --i)

const ll N = 5002, inf = 1e18L;
ll n, k;
ll a[N];
ll x[N][N], c[N][N];
ll dp[N][2];

void dnc(ll cur, ll l, ll r, ll optl, ll optr) {
    if(l > r) return;
    ll d = (l + r) / 2;
    ll prv = 1 - cur;
    pair<ll, ll> best = {inf, -1};

    for(ll i = optl; i <= min(d, optr); ++i) {
        best = min(best, {dp[i - 1][prv] + c[i][d], i});
    }

    dp[d][cur] = best.fr;
    ll opt = best.sc;

    dnc(cur, l, d - 1, optl, opt);
    dnc(cur, d + 1, r, opt, optr);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k; ++k;
    fur(i, 1, n)
        cin >> a[i];

    fur(i, 1, n) {
        x[i][i] = 0;
        ruf(j, i - 1, 1) {
            x[i][j] = x[i][j + 1] + (a[i] ^ a[j]);
        }
    }

    fur(i, 1, n) {
        c[i][i] = 0;
        fur(j, i + 1, n) {
            c[i][j] = c[i][j - 1] + x[j][i];
        }
    }

    for(ll i = 1; i <= n; ++i)
        dp[i][0] = inf;
    dp[0][0] = 0;
    for(ll j = 1; j <= k; ++j) {
        dp[0][j&1] = inf;
        dnc(j&1, 1, n, 1, n);
        /* for(ll i = 1; i <= n; ++i) */
        /*     cout << dp[i][j&1] << ' '; */
        /* cout << nl; */
    }
    cout << dp[n][k&1] << "\n";
}
