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
    ll n, m, s, A, B;
    cin >> n >> m >> s >> A >> B;
    vl a(n), b(m);
    fur(i, 0, n - 1)
        cin >> a[i];
    fur(i, 0, m - 1)
        cin >> b[i];

    /* solving the problem */
    sort(rall(a));
    sort(rall(b));
    ll ans = 0;

    ll wt = 0;
    ll val = 0;

    ll j = -1;
    ll i = -1;
    while(j + 1 < m && B + wt <= s) {
        ++j;
        wt += B;
        val += b[j];
        ans = max(ans, val);
    }

    ans = max(ans, val);
    while(j > -1) {
        while(i + 1 < n && A + wt <= s) {
            ++i;
            wt += A;
            val += a[i];
            ans = max(ans, val);
        }
        wt -= B;
        val -= b[j];
        --j;
    }

    while(i + 1 < n && A + wt <= s) {
        ++i;
        wt += A;
        val += a[i];
        ans = max(ans, val);
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

