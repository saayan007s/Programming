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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    for(auto &u : a)
        cin >> u;

    /* solving the problem */
    sort(all(a));
    while(k--) {
        ll val;
        cin >> val;
        ll lo = 0;
        ll hi = n;
        while(lo + 1 != hi) {
            ll mid = (lo + hi) / 2;
            (a[mid] <= val ? lo : hi) = mid;
        }
        cout << (a[lo] == val ? "YES" : "NO") << nl;
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

