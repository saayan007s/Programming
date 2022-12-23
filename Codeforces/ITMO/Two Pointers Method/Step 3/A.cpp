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
    ll n, p;
    cin >> n >> p;
    vl a(n);
    for(auto &u : a)
        cin >> u;

    /* solving the problem */
    ll total = 0;
    ll c = 0;
    fur(i, 0, n - 1) {
        total += a[i];
        a.pb(a[i]);
    }
    c += (p / total) * n;
    p %= total;

    ll k = 0;
    ll len = n;
    ll sum = 0;
    ll l = 0;
    fur(r, 0, 2*n - 1) {
        sum += a[r];
        while(sum - a[l] >= p) {
            sum -= a[l++];
        }
        if(sum >= p) {
            if(r - l + 1 < len) {
                k = l;
                len = r - l + 1;
            }
        }
    }
    cout << k%n + 1 << ' ' << c + len << nl;
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

