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

const ll N = 5001;
const ll inf = 1e18L;
ll n, k;
ll a[N];
ll c[N][N];
ll dp[N][N];

void dnc(ll lvl, ll l, ll r, ll optl, ll optr) {
    if(l > r)
        return;

    ll d = (l + r) / 2;
    pl best = {-inf, - 1};

    fur(i, max(1ll, optl), min(d, optr)) {
        if(dp[i - 1][lvl - 1] != -inf)
            best = max(best, {dp[i - 1][lvl - 1] + c[i][d], i});
    }

    dp[d][lvl] = best.fr;
    ll opt = best.sc;

    dnc(lvl, l, d - 1, optl, opt);
    dnc(lvl, d + 1, r, opt, optr);
}

void solve() {
    cin >> n >> k;    
    fur(i, 1, n) cin >> a[i];

    fur(i, 1, n) {
        c[i][i] = a[i];
        fur(j, i + 1, n)
            c[i][j] = c[i][j - 1] | a[j];
    }

    fur(i, 0, n)
        fur(j, 0, k)
            dp[i][j] = -inf;
    dp[0][0] = 0;

    fur(j, 1, k)
        dnc(j, 1, n, 1, n);

    cout << dp[n][k] << nl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	ll t = 1;
    cin >> t;
    while(t--)
    {
        solve();
    }
}
