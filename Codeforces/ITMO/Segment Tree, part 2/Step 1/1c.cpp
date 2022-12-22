#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

using item = long long;
struct SegTree {
    ll n;
    item id;
    vector<item> tree;

    SegTree(int N) {
        init(N, id);
    }

    SegTree(int N, item x) {
        init(N, x);
    }

    void init(int N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, 0);
    }

    ll opp(ll a, ll b) {
        if(b == -1)
            return a;
        return b;
    }

    void apply(ll &a, ll b) {
        a = opp(a, b);
    }

    void prop(ll node, ll lo, ll hi) {
        if(lo == hi)
            return;
        apply(tree[2*node], tree[node]);
        apply(tree[2*node + 1], tree[node]);
        tree[node] = -1;    
    }

    void assign(ll node, ll lo, ll hi, ll l, ll r, ll v) {
        prop(node, lo, hi);
        if(r < lo || hi < l)
            return;
        if(l <= lo && hi <= r) {
            apply(tree[node], v);
            return;
        }

        ll m = (lo + hi) / 2;
        assign(2*node, lo, m, l, r, v);
        assign(2*node + 1, m + 1, hi, l, r, v);
    }

    void assign(ll l, ll r, ll v) {
        assign(1, 0, n - 1, l, r, v);
    }

    ll get(ll node, ll lo, ll hi, ll i) {
        if(lo == hi)
            return tree[node];
        prop(node, lo, hi);
        ll m = (lo + hi) / 2;
        if(i <= m)
            return get(2*node, lo, m, i);
        return get(2*node + 1, m + 1, hi, i);
    }

    ll get(ll i) {
        return get(1, 0, n - 1, i);
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    SegTree st(n, 0);
    fur(i, 1, st.n - 1)
        st.tree[i] = -1;

    while(m--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            --r;
            st.assign(l, r, v);
        } else {
            ll i;
            cin >> i;
            cout << st.get(i) << nl;
        }
    }
}
