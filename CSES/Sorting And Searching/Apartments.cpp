//
#include <bits/stdc++.h>
using namespace std;
 
/* higher types */
typedef long long ll;
typedef long double ld;
 
/* pairs */
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<double, double> pd;
typedef pair<ld, ld> pld;
 
/* vectors */
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<bool> vb;
 
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;
typedef vector<pld> vpld;
 
/* 2d vectors */
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vd> vvd;
typedef vector<vld> vvld;
typedef vector<vs> vvs;
typedef vector<vb> vvb;
 
/* initialisation */
#define initvvi(mat, n, x) for(auto &u : mat) u = vi(n, x);
#define initvvl(mat, n, x) for(auto &u : mat) u = vl(n, x);
#define initvvb(mat, n, x) for(auto &u : mat) u = vb(n, x);
#define initvvd(mat, n, x) for(auto &u : mat) u = vd(n, x);
#define initvvs(mat, n, x) for(auto &u : mat) u = vs(n, x);
 
/* loops */
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define each(u, v) for(auto &u : v )
 
/* input */
#define rv(v) for(auto &u : v) cin >> u;
#define rm(mat, m) for(ll j = 0; j <= (ll)(m-1)) for(auto &u : mat[j]) cin >> u;
 
/* output */
#define pv(v) for(auto &x : v) cout << x << ' '; cout << nl;
#define pm(m) for(auto &n : m) pv(n);
 
/* shortforms */
#define fr first 
#define sc second
#define pb push_back
 
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
/* constants */
const ll infl = numeric_limits<long long int>::max();
const ll infi = numeric_limits<int>::max();
const int modi = 1e9 + 7;
const ll modl = 1e9 + 7;
 
void solve()
{
    /* taking input */
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    rv(a);
    rv(b);
 
    /* solving the problem */
    sort(all(a));
    sort(all(b));
 
    int i = 0, j = 0;
    int ans = 0;
 
    while(i < n && j < m)
    {
        if(abs(a[i] - b[j]) <= k){
            ans++;
            i++;
            j++;
        }
        else if(a[i] > b[j])
            j++;
        else
            i++;
    }
 
    cout << ans << nl;
}
 
int main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        /* freopen("output.txt","w",stdout); */
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	ll t = 1;
    /* cin >> t; */
    while(t--)
    {
        solve();
    }
}
