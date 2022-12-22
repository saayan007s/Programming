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

ll n, k;
vl a;

bool good(ll x) {
    ll stu = 0;
    fur(i, 0, n - 1) {
        stu += min(a[i], x);
    }
    return stu >= x*k;
}

void solve()
{
    /* taking input */
    cin >> k >> n;
    a.resize(n);
    fur(i, 0, n - 1)
        cin >> a[i];

    /* solving the problem */
    /* sort(all(a)); */
    ll l = 0;
    ll r = 1;
    while(good(r))
        r *= 2;
    while(l + 1 != r) {
        cerr << l << ' ' << r << nl;
        ll m = (l + r) / 2;
        (good(m) ? l : r) = m;
    }
    cout << l;
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

