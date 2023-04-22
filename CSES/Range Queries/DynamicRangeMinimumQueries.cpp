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
 
ll sum(ll node, ll nlo, ll nh, ll ql, ll qh)
{
    if(nlo > qh || nh < ql)
        return 1e15;
    if(nlo >= ql && nh <= qh)
        return tree[node];
    ll mid = (nlo + nh)/2;
    return min(sum(2*node, nlo, mid, ql, qh), sum(2*node + 1, mid + 1, nh, ql, qh));
}
 
void update(ll node, ll nlo, ll nh, ll ql, ll qh, ll val)
{
    if(nlo > qh || nh < ql)
        return;
    if(nlo >= ql && nh <= qh){
        tree[node] = val;
        return;
    }
 
    ll mid = (nlo + nh)/2;
    update(2*node, nlo, mid, ql, qh, val);
    update(2*node + 1, mid + 1, nh, ql, qh, val);
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}
 
void solve()
{
    cin >> n >> q;
    vl a(n);
    for(auto &u : a)
        cin >> u;
 
    while(__builtin_popcountll(n) != 1)
    {
        a.pb(1e10);
        ++n;
    }
    
    tree.resize(2 * n);
    fur(i, 0, n - 1)
        tree[n + i] = a[i];
    ruf(i, n - 1, 1)
        tree[i] = min(tree[2*i], tree[2*i + 1]);
 
    while(q--)
    {
        ll type;
        cin >> type;
        if(type == 2)
        {
            ll a, b;
            cin >> a >> b;
            --a;
            --b;
            cout << sum(1, 0, n - 1, a, b) << nl;
        }
        else{
            ll k, u;
            cin >> k >> u;
            --k;
            update(1, 0, n - 1, k, k, u);
        }
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
