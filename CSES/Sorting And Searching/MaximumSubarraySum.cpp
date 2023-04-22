#include <bits/stdc++.h>
using namespace std;
 
/* higher types */
typedef long long ll;
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
const ll infl = numeric_limits<long long int>::max();
const int infi = numeric_limits<int>::max();
const int modi = 1e9 + 7;
const ll modl = 1e9 + 7;
 
void solve()
{
    ll n;
    cin >> n;
    vl a(n);
    vl dp(n);
    ll ans = INT_MIN;
    fur(i, 0, n-1)
    {
        cin >> a[i];
        if(i == 0){
            dp[i] = a[i];
            ans = max(ans, dp[i]);
            continue;
        }
        dp[i] = max(a[i], dp[i-1] + a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
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
