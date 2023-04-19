#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const ll N = 2e5L + 1;
const ll K = 21;
const ll inf = 1e18L;

ll n, k;
ll a[N];
ll dp[N][K];
ll res = 0;
ll cnt[N] = {};

void remove(ll l, ll r) {
    fur(i, l, r)
        res -= --cnt[a[i]];
}

void add(ll l, ll r) {
    fur(i, l, r)
        res += cnt[a[i]]++;
}

void dnc(ll lvl, ll l, ll r, ll optl, ll optr) {
    if(l > r) return;

    ll d = (l + r) / 2;
    pl best = {inf, -1};

    fur(i, max(1ll, optl), min(d, optr)) {
        best = min(best, {dp[i - 1][lvl - 1] + res, i});
        res -= --cnt[a[i]];
    }
    add(max(1ll, optl), min(d, optr));

    dp[d][lvl] = best.fr;
    ll opt = best.sc;

    // [optl, d] -> [optl, dt] where dt <= d
    ll dt = (l + d - 1) / 2;
    remove(dt + 1, d);
    dnc(lvl, l, d - 1, optl, opt);
    add(dt + 1, d);

    // [optl, d] -> [opt, dt] where optl <= opt && d <= dt
    dt = (d + 1 + r) / 2;
    remove(optl, opt - 1);
    add(d + 1, dt);
    dnc(lvl, d + 1, r, opt, optr);
    add(optl, opt - 1);
    remove(d + 1, dt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fur(i, 1, n) cin >> a[i];

    dp[0][1] = inf;
    fur(i, 1, n) {
        res += cnt[a[i]]++;
        dp[i][1] = res;
    }

    fur(j, 2, k) {
        dp[0][j] = inf;
        ll d = (n + 1) / 2;
        remove(d + 1, n);
        dnc(j, 1, n, 1, n);
        add(d + 1, n);
    }

    cout << dp[n][k] << nl;
}
