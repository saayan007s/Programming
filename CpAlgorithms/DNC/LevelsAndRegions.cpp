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

using ld = long double;

const ll mxn = 2e5L + 1;
const ll mxk = 51;
const ll inf = 1e18L;

ll n, k;
ll t[mxn], s[mxn];
ld x[mxn], a[mxn];
ld dp[mxn][mxk];

ld C(ll l, ll r) {
    return (x[r] - x[l - 1]) - (double)s[l - 1] * (a[r] - a[l - 1]);
}
void ch() {
    cout << nl;
    cout << "check " << dp[2][1] << ' ' << C(1, 2) << nl;
}
void dnc(ll lvl, ll l, ll r, ll optl, ll optr) {
    /* ch(); */
    /* cout << lvl << ' ' << l << ' ' << r << ' ' << optl << ' ' << optr << nl; */
    if(l > r)
        return;

    ll mid = (l + r) / 2;
    pair<ld, ll> best = {inf, -1};

    fur(i, max(1ll, optl), min(mid, optr)) {
        best = min(best, {dp[i - 1][lvl - 1] + C(i, mid), i});
    }

    dp[mid][lvl] = best.fr;
    ll opt = best.sc;

    dnc(lvl, l, mid - 1, optl, opt);
    dnc(lvl, mid + 1, r, opt, optr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fur(i, 1, n)
        cin >> t[i];

    s[0] = a[0] = x[0] = 0;
    fur(i, 1, n) {
        s[i] = s[i - 1] + t[i];
        a[i] = a[i - 1] + 1.0/t[i];
        x[i] = (double)s[i] / (double)t[i];
        x[i] += x[i - 1];
        /* cout << s[i] << ' ' << a[i] << ' ' << x[i] << nl; */
    }
    /* cout << nl; */
    /* cout << nl; */

    dp[0][1] = 0;
    fur(i, 1, n) {
        dp[i][1] = C(1, i);
        /* cout << C(1, i) << ' '; */
    }
    /* cout << nl; */
    /* fur(i, 1, n) */
        /* cout << dp[i][1] << ' '; */
    /* cout << nl << nl; */

    fur(j, 2, k) {
        dp[0][j] = 0;
        dnc(j, 1, n, 1, n);
    }

    /* fur(j, 1, k) { */
    /*     fur(i, 1, n) */
    /*         cout << dp[i][j] << ' '; */
    /*     cout << nl; */
    /* } */
    /* cout << nl; */

    cout << setprecision(20) << dp[n][k] << nl;
    /* cout << nl; */
    /* fur(i, 1, n) { */
    /*     fur(j, i, n) */
    /*         cout << C(i, j) << ' '; */
    /*     cout << nl; */
    /* } */

    /* ch(); */
}
