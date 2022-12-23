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
    ll n, s;
    cin >> n >> s;
    vpl a(n);
#define wt first
#define val second
    fur(i, 0, n - 1)
        cin >> a[i].wt;
    fur(i, 0, n - 1)
        cin >> a[i].val;

    /* solving the problem */
    ll ans = 0;
    ll l = 0;
    ll value = 0;
    ll weight = 0;
    fur(r, 0, n - 1) {
        value += a[r].val;
        weight += a[r].wt;
        while(weight > s) {
            value -= a[l].val;
            weight -= a[l].wt;
            ++l;
        }

        ans = max(ans, value);
    } 
    cout << ans << nl;
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

