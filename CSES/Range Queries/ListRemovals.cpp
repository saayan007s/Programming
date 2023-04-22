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
 
ll search(ll node, ll lo, ll hi, ll sum) {
    /* cout << sum << ' '; */
    if(lo == hi)
        return lo;
 
    ll ch1 = 2*node;
    ll ch2 = 2*node + 1;
 
    ll mid = (lo + hi)/2;
 
    if(tree[ch1] >= sum)
        return search(ch1, lo, mid, sum);
    else
        return search(ch2, mid + 1, hi, sum - tree[ch1]);
}
 
void update(ll node, ll lo, ll hi, ll pos, ll val) {
    if(lo == hi) {
        tree[node] = val;
        return;
    }
 
    ll mid = (lo + hi) / 2;
    if(lo <= pos && pos <= mid)
        update(2*node, lo, mid, pos, val);
    else
        update(2*node + 1, mid + 1, hi, pos, val);
    tree[node] = tree[2*node] + tree[2*node + 1];
}
 
void print()
{
    fur(i, 1, 2*n - 1) {
        cout << tree[i] << ' ';
        if(!(i & (i + 1)))
            cout << nl;
    }
    cout << nl;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n;
    vl x(n);
    vl p(n);
 
    fur(i, 0, n - 1) cin >> x[i];
    fur(i, 0, n - 1) cin >> p[i];
 
    while((ll)__builtin_popcountll(n) != 1)
        ++n;
    tree.resize(2 * n);
    fur(i, 0, x.size() - 1)
        tree[n + i] = 1;
    ruf(i, n - 1, 1)
        tree[i] = tree[2*i] + tree[2*i + 1];
    /* print(); */
 
    fur(j, 0, (ll)p.size() - 1) {
        ll u = p[j];
        ll i = search((ll)1, (ll)0, n - 1, u);
        /* cout << nl; */
        /* cout << "answer = " << x[i] << nl; */
        update((ll)1, (ll)0, n - 1, i, 0);
        /* cout << "index = " << i << nl; */
        /* print(); */
        cout << x[i] << ' ';
    }
    return 0;
}
