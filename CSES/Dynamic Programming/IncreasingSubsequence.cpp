#include <bits/stdc++.h>
using namespace std;
 
/* higher types */
typedef long long ll;
typedef long double ld;
 
/* pairs */
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
 
/* vectors */
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
 
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
 
/* loops */
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define each(u, v) for(auto (&u) : (v) )
 
/* initialisations */
#define mat(x, y) fur(i, 0, x.length() - 1) { fur(j, 0, x[0].length() - 1) { x[i][j] = y; } }
#define arr(x, y) fur(i, 0, x.length() - 1) { x[i] = y; }
 
#define fr first 
#define sc second 
#define pb push_back
 
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
const ll mod = 1e9 + 7;
const ll inf = 1e9;
 
void solve()
{
    /* taking input */
    ll n;
    cin >> n;
    vl a(n);
    each(u, a){
        cin >> u;
    } 
 
    /* solving the problem */
    vi d(n+1, inf);
    d[0] = -inf;
 
    fur(i, 0, n-1)
    {
        ll j = upper_bound( all(d), a[i] ) - d.begin();
        if(d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }
    
    ll ans = 0;
    fur(i, 0, n)
        if(d[i] < inf)
            ans = i;
    cout << ans << nl;
}
 
signed main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /* freopen("output.txt","w",stdout); */
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	ll t = 1;
    while(t--)
    {
        solve();
    }
}
