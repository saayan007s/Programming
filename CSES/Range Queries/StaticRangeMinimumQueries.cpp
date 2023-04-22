#include <bits/stdc++.h>
using namespace std;
 
/* higher types */
typedef int64_t ll;
typedef long double ld;
 
/* pairs */
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
/* vectors */
typedef vector<int> vi;
typedef vector<ll> vl;
 
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
/* loops */
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
 
/* shortforms */
#define fr first 
#define sc second
#define pb push_back
#define mp make_pair
 
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
/* constants */
const ll infl = numeric_limits<int64_t>::max();
const int infi = numeric_limits<int>::max();
const int modi = 1e9 + 7;
const ll modl = 1e9 + 7;
 
void solve()
{
    ll n, q;
    cin >> n >> q;
 
    ll x[n + 1];
    fur(i, 1, n)
        cin >> x[i];
 
    ll lg = ceil(log2(n)) - 1;
    ll mn[n + 1][lg + 1];
    fur(i, 1, n)
        mn[i][0] = x[i];
 
    for(ll j = 1; j <= lg; ++j)
    {
        for(ll i = 1; i + (1 << j) - 1 <= n; ++i)
        {
            mn[i][j] = min( mn[i][j-1], mn[i + (1<<(j-1))][j-1]);
        }
    }
 
    fur(i, 1, q)
    {
        ll l, r;
        cin >> l >> r;
        if(l == r)
        {
            cout << mn[l][0] << nl;
            continue;
        }
 
        ll len = r - l + 1;
        len = ceil(log2(len)) - 1;
 
        ll ans = mn[l][len];
        ans = min(ans, mn[r - (1 << len) + 1][len]);
 
        cout << ans << nl;
    }
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
	ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
