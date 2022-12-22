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

ll b, s, c, nb, ns, nc, pb, ps, pc, r;

bool good(ll x) {
    ll price = 0;
    ll one = max((ll)0, (b*x - nb) * pb);
    ll two = max((ll)0, (s*x - ns) * ps);
    ll thr = max((ll)0, (c*x - nc) * pc);
    return one + two + thr <= r;
}

void solve()
{
    /* taking input */
    string tmp;
    cin >> tmp;
    b = s = c = 0;
    for(auto u : tmp) {
        b += u == 'B';
        s += u == 'S';
        c += u == 'C';
    }
    cin >> nb >> ns >> nc >> pb >> ps >> pc >> r;

    /* solving the problem */
    ll lo = 0;
    ll hi = 1;
    while(good(hi))
        hi *= 2;

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

