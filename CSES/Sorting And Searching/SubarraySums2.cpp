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
 
/* 2d vectors */
typedef vector<vi> vvi;
typedef vector<vl> vvl;
 
/* initialisation */
#define initvvi(mat, n, x) for(auto u : mat) u = vi(n, x);
#define initvvl(mat, n, x) for(auto u : mat) u = vl(n, x);
 
/* loops */
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
 
/* input */
#define rv(v) for(auto &u : v) cin >> u;
#define rm(mat, m) for(ll j = 0; j <= (ll)(m-1)) for(auto u : mat[j]) cin >> u;
 
/* output */
#define pv(v) for(auto x : v) cout << x << ' '; cout << nl;
#define pm(m) for(auto n : m) pv(n);
 
/* shortforms */
#define fr first 
#define sc second
#define pb push_back
 
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
    ll n, x;
    cin >> n >> x;
    vl a(n + 1);
    a[0] = 0;
    fur(i, 1, n)
    {
        cin >> a[i];
        a[i] += a[i-1];
    }
 
    // sort(all(a));
    // cout << (a.end() == lower_bound(a.begin(), a.end(), x - 5)) << nl;
    // pv(a);
    ll ans = 0;
    map<ll, ll> m;
    fur(i, 0, n)
    {
        ans += m[a[i] - x];
        m[a[i]]++;
    }
    cout << ans <<nl;
}
 
int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ios::sync_with_stdio(0);
    cin.tie(0);
 
	ll t = 1;
    /* cin >> t; */
    while(t--)
    {
        solve();
    }
}
