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
ll a[100001];

bool good(ll x) {
    ll seg = 1;
    ll s = 0;
    fur(i, 1, n) {
        if(a[i] > x)
            return 0;
        if(s + a[i] > x) {
            s = 0;
            ++seg;
        }
        s += a[i];
    }
    return seg <= k;
}

void solve()
{
    cin >> n >> k;
    fur(i, 1, n)
        cin >> a[i];

    ll lo = 0;
    ll hi = 1;
    while(!good(hi))
        hi *= 2;

    while(lo + 1 != hi) {
        ll m = (lo + hi) / 2;
        (good(m) ? hi : lo) = m;
    }
    
    cout << hi << nl;
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

