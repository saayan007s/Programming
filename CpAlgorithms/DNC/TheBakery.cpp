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

struct FT { // fenwick tree
    vl tree;
    ll n;

    FT(ll N) {
        tree.resize(N);
        n = N - 1;
    }

    void mod(ll pos, ll val) {
        while(pos <= n) {
            tree[pos] += val;
            pos += pos&-pos;
        }
    }

    ll qry(ll pos) {
        ll res = 0;
        while(pos >= 1) {
            res += tree[pos];
            pos -= pos&-pos;
        }
        return res;
    }

    ll qry(ll l, ll r) {
        return qry(r) - qry(l - 1);
    }
};

const ll N = 35001;
const ll K = 51;
const ll inf = 1e18L;
ll n, k;
ll a[N];
ll nx[N], pv[N];
ll dp[N][K];
FT fen(N);

void dnc(ll lvl, ll l, ll r, ll optl, ll optr) {
    if(l > r) return;
    ll d = (l + r) / 2;
    pl best = {-inf, -1};

    fur(i, max(1ll, optl), min(d, optr)) {
        best = max(best, {dp[i - 1][lvl - 1] + fen.qry(i, d), i});
        if(nx[i] != -1)
            fen.mod(nx[i], 1);
    }
    fur(i, max(1ll, optl), min(d, optr)) {
        if(nx[i] != -1)
            fen.mod(nx[i], -1);
    }

    dp[d][lvl] = best.fr;
    ll opt = best.sc;
    dnc(lvl, l, d - 1, optl, opt);

    fur(i, max(1ll, optl), opt - 1)
        if(nx[i] != -1)
            fen.mod(nx[i], 1);

    dnc(lvl, d + 1, r, opt, optr);
    fur(i, max(1ll, optl), opt - 1)
        if(nx[i] != -1)
            fen.mod(nx[i], -1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fur(i, 1, n) cin >> a[i];

    ll last[n + 1] = {};

    fur(i, 1, n) {
        if(last[a[i]] == 0) pv[i] = -1;
        else pv[i] = last[a[i]];
        last[a[i]] = i;
    }

    fur(i, 1, n) last[i] = 0;
    ruf(i, n, 1) {
        if(last[a[i]] == 0) nx[i] = -1;
        else nx[i] = last[a[i]];
        last[a[i]] = i;
    }

    fur(i, 1, n)
        if(pv[i] == -1)
            fen.mod(i, 1);

    dp[0][1] = -inf;
    fur(i, 1, n)
        dp[i][1] = fen.qry(i);

    fur(j, 2, k) {
        dp[0][j] = -inf;
        dnc(j, 1, n, 1, n);
    }

    /* fur(i, 1, k) { */
    /*     fur(j, 1, n) */
    /*         cout << dp[j][i] << ' '; */
    /*     cout << nl; */
    /* } */

    cout << dp[n][k];
}
