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

void solve()
{
    /* taking input */
    ll n;
    cin >> n;
    vl a(n + 2);
    a[0] = -1e10;
    a[n + 1] = 1e10;
    fur(i, 1, n)
        cin >> a[i];

    /* solving the problem */
    sort(all(a));
    ll k;
    cin >> k;
    while(k--) {
        ll l, r;
        cin >> l >> r;

        ll lo, hi, i, j;

        lo = -1;
        hi = n + 1;
        while(lo + 1 != hi) {
            ll mid = (lo + hi) / 2;
            if(a[mid] >= l)
                hi = mid;
            else lo = mid;
        }
        j = hi;

        lo = 0;
        hi = n + 2;
        while(lo + 1 != hi) {
            ll mid = (lo + hi) / 2;
            if(a[mid] <= r)
                lo = mid;
            else hi = mid;
        }
        i = lo;

        cout << i - j + 1 << ' ';
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

