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

typedef long double ld;

void solve()
{
    /* taking input */
    ld c;
    cin >> c;

    /* solving the problem */
    ld l = 0;
    ld r = 1e8;
    ld e = 1e-7;
    while(l + e < r) {
        ld m = (l + r) / 2;
        ld a = m*m + sqrt(m);
        cerr << m << ' ' << a << nl;
        (a >= c ? r : l) = m;
    }
    cout << setprecision(20) << r;
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

