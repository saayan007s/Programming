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
ll w[N], x[N];
ll c[N][N];
ll dp[N], prv[N];

void dnc(ll lvl, ll l, ll r, ll optl, ll optr) {
    if(l > r) return;
    ll d = (l + r) / 2;
    pl best = {inf, -1};

    fur(i, max(1ll, optl), min(d, optr)) {
        best = min(best, {prv[i - 1] + c[i][d], i});
    }

    dp[d] = best.fr;
    ll opt = best.sc;

    dnc(lvl, l, d - 1, optl, opt);
    dnc(lvl, d + 1, r, opt, optr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fur(i, 1, n)
        cin >> x[i] >> w[i];

    w[0] = 0;
    fur(i, 1, n)
        w[i] += w[i - 1];

    fur(i, 1, n) {
        c[i][i] = 0;
        ll p = i;
        ll cost = 0;
        fur(j, i + 1, n) {
            cost += (x[j] - x[p]) * (w[j] - w[j - 1]);
            while(w[p] - w[i - 1] < w[j] - w[p]) {
                cost += (x[p + 1] - x[p]) * ((w[p] - w[i - 1]) - (w[j] - w[p]));
                ++p;
            }
            c[i][j] = cost;
        }
    }

    fur(i, 1, n) {
        prv[i] = c[1][i];
    }

    fur(j, 2, k) {
        prv[0] = inf;
        dnc(j, 1, n, 1, n);
        swap(dp, prv);
    }

    cout << prv[n];
}
