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
 
ll n, q;
vl tree;
 
ll query(ll node, ll lo, ll hi, ll ql, ll qh, ll val)
{
    if(lo > qh || hi < ql)
        return 0;
    if(lo >= ql && hi <= qh)
    {
        if(val != -1)
            tree[node] += val;
        return tree[node];
    }
 
    ll mid = (lo + hi)/2;
    ll sum = query(2*node, lo, mid, ql, qh, val) + query(2*node + 1, mid + 1, hi, ql, qh, val);
    return sum + tree[node];
}
 
void solve()
{
    cin >> n >> q;
    vl a(n);
    for(auto &u : a)
        cin >> u;
 
    while(__builtin_popcountll(n) != 1)
    {
        a.pb(0);
        ++n;
    }
    
    tree.resize(2 * n);
    fur(i, 0, n - 1)
        tree[n + i] = a[i];
 
    while(q--)
    {
        ll type;
        cin >> type;
        if(type == 1)
        {
            ll a, b, u;
            cin >> a >> b >> u;
            --a; --b;
            query(1, 0, n - 1, a, b, u);
        }
        if(type == 2){
            ll k;
            cin >> k;
            --k;
            cout << query(1, 0, n - 1, k, k, -1) << nl;
        }
        // fur(i, 1, 2 * n - 1)
        // {
            // cout << tree[i] << ' ';
            // if((i & (i + 1)) == 0)
                // cout << nl;
        // }
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
