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
    ll w, h, n;
    cin >> w >> h >> n;

    /* solving the problem */
    auto feas = [&](ll k) -> bool {
        return (k/w) * (k/h) >= n;
    };
    ll lo = 0;
    ll hi = 1;
    while(!feas(hi))
        hi += hi;

    while(lo + 1 != hi) {
        ll mid = (lo + hi) / 2;
        (feas(mid) ? hi : lo) = mid;
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

