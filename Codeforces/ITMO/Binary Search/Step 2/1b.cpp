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

ll n, k;
vector<ld> a;
ll feas(ld m) {
    ll p = 0;
    for(auto u : a)
        p += floor(u/m);
    return p;
}
void solve()
{
    /* taking input */
    cin >> n >> k;
    a = vector<ld> (n);
    for(auto &u : a)
        cin >> u;

    /* solving the problem */
    ld l = 0;
    ld r = 1e7 + 1;
    ld ep = 1e-6;
    while(l + ep < r) {
        ld m = (l + r) / 2;
        (feas(m) >= k ? l : r) = m;
    }
    /* cout << feas(200.5) << nl;; */
    /* for(auto u : a) { */
    /*     cout << u << ' ' << floor(u / 200.5) << nl; */
    /* } */
    cout << setprecision(20) << l << nl;
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

