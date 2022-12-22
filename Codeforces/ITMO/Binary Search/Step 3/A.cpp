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
vl x, v;

typedef long double ld;

bool good(ld t) {
    ld l = x[0] - v[0]*t;
    ld r = x[0] + v[0]*t;

    fur(i, 1, n - 1) {
        l = max(l, x[i] - v[i]*t);
        r = min(r, x[i] + v[i]*t);
    }
    return l <= r;
}
void solve()
{
    /* taking input */
    cin >> n;
    x.resize(n);
    v.resize(n);
    fur(i, 0, n - 1)
        cin >> x[i] >> v[i];

    /* solving the problem */
    ld l = 0;
    ld r = 1;
    ld e = 1e-7;
    
    while(!good(r))
        r *= 2;
    while(l + e < r) {
        cerr << l << ' ' << r << nl;
        ld m = (l + r) / 2;
        (good(m) ? r : l) = m;
    }
    cout << setprecision(20) << r << nl;
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

