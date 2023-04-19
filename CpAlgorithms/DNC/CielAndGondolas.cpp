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

const ll N = 4001;
const ll K = 801;
const ll inf = 1e18L;

ll n, k;
ll u[N][N];
ll c[N][N];
ll dp[N][K];

void dnc(ll lvl, ll l, ll r, ll optl, ll optr) {
    if(l > r)
        return;

    ll mid = (l + r) / 2;
    pl best = {inf, -1};

    fur(i, optl, min(mid, optr)) {
        best = min(best, {dp[i - 1][lvl - 1] + c[i][mid], i});
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
    fur(i, 1, n) {
        u[i][0] = 0;
        fur(j, 1, n) {
            cin >> u[i][j];
            u[i][j] += u[i][j - 1];
        }
    }

    fur(i, 1, n) {
        c[i][i] = 0;
        fur(j, i + 1, n) {
            c[i][j] = c[i][j - 1] + u[j][j] - u[j][i - 1];
        }
    }

    dp[0][0] = 0;
    fur(i, 1, n)
        dp[i][0] = inf;

    fur(j, 1, k)
        dnc(j, 1, n, 1, n);

    cout << dp[n][k];
}
