#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll n, k;
ll a[10001];
bool good(ll m) {
    ll cows = 1;
    ll cur = lower_bound(a + 1, a + n + 1, a[1] + m) - a;
    while(cur != n + 1) {
        ++cows;
        cur = lower_bound(a + 1, a + n + 1, a[cur] + m) - a;
    }
    return cows >= k;
}
void solve()
{
    cin >> n >> k;
    fur(i, 1, n)
        cin >> a[i];

    ll lo = 1;
    ll hi = 1e10;

    while(lo + 1 != hi) {
        ll m = (lo + hi) / 2;
        (good(m) ? lo : hi) = m;
    }
    cout << lo << nl;
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

