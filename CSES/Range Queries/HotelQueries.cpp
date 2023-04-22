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
 
#define fr first 
#define sc second
#define pb push_back
#define mp make_pair
 
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
ll n;
vl tree;
 
ll find_hotel(ll r)
{
    ll node = 1;
    while(2 * node <= 2 * n - 1) {
        if(tree[2 * node] >= r)
            node = 2 * node;
        else if(tree[2 * node + 1] >= r)
            node = 2 * node + 1;
        else
            return 0;
    }
    if(tree[node] < r)
        return 0;
 
    ll ans = node;
    tree[node] -= r;
    while(node >= 1) {
        node /= 2;
        tree[node] = max(tree[2*node], tree[2*node + 1]);
    }
    return ans - n + 1;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll m;
    cin >> n >> m;
    vl a(n);
    ll r[m];
    for(auto &u : a) cin >> u;
    for(auto &u : r) cin >> u;
 
    while((ll)__builtin_popcountll(n) != 1)
        ++n;
    tree.resize(2 * n);
    fur(i, 0, (ll)a.size() - 1)
        tree[n + i] = a[i];
 
    // fur(i, 1, 2*n - 1) {
        // cout << tree[i] << ' ';
        // if(!(i & (i + 1)))
            // cout << nl;
    // }
 
    ruf(i, n - 1, 1)
        tree[i] = max(tree[2*i], tree[2*i + 1]);
 
    fur(i, 0, m - 1) {
        ll ans = find_hotel(r[i]);
        cout << ans << ' ';
    }
}
