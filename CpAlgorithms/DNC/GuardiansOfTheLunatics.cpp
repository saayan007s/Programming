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

const ll inf = 1e18L;
const ll mxn = 8001;
const ll mxg = 801;

ll n, g;
ll s[mxn];
ll dp[mxg][mxn];

ll C(ll l, ll r) {
    return (r - l + 1) * (s[r] - s[l - 1]);
}

void dnc(ll i, ll l, ll r, ll optl, ll optr) {
    if(l > r)
        return;

    ll j = (l + r) / 2;
    pl best = {inf, -1};

    fur(k, optl, min(j, optr)) {
        if(dp[i - 1][k - 1] != inf)
            best = min(best, make_pair(dp[i - 1][k - 1] + C(k, j), k));
    }

    dp[i][j] = best.fr;
    ll opt = best.sc;

    dnc(i, l, j - 1, optl, opt);
    dnc(i, j + 1, r, opt, optr);
}

void solve() {
    s[0] = 0;
    fur(i, 1, n)
        s[i] += s[i - 1];

    dp[0][0] = 0;
    fur(j, 1, n)
        dp[0][j] = inf;

    fur(i, 1, g)
        dnc(i, 1, n, 1, n);

    cout << dp[g][n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> g;
    fur(i, 1, n)
        cin >> s[i];
    solve();
}
