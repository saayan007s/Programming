#include <bits/stdc++.h>
using namespace std;
 
typedef int64_t ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define each(u, v) for(auto &u : v )
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
ll n;
vl seg, sum, pref, suf;
 
void update(ll pos, ll val) {
    pos += n;
    sum[pos] = val;
    pref[pos] = suf[pos] = seg[pos] = max((ll)0, val);
    pos /= 2;
    while(pos >= 1) {
        ll a = 2*pos;
        ll b = a + 1;
        sum[pos] = sum[a] + sum[b];
        pref[pos] = max(pref[a], sum[a] + pref[b]);
        suf[pos] = max(suf[b], sum[b] + suf[a]);
        seg[pos] = max({seg[a], seg[b], suf[a] + pref[b]});
 
        pos /= 2;
    }
}
 
void solve()
{
    ll N, q;
    cin >> N >> q;
    n = N;
    while(__builtin_popcount(n) != 1)
        ++n;
    seg.resize(2 * n);
    sum.resize(2 * n);
    suf.resize(2 * n);
    pref.resize(2 * n);
 
    fur(i, 0, N - 1) {
        ll tmp;
        cin >> tmp;
        update(i, tmp);
    }
 
    while(q--) {
        ll i, v;
        cin >> i >> v;
        update(--i, v);
        cout << seg[1] << nl;
    }
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
	ll t = 1;
    /* cin >> t; */
    while(t--)
    {
        solve();
    }
}
