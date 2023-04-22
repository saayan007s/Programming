#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using vi = vector<int>;
using vl = vector<long long>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;
 
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
struct item {
    ll val, a, d;
 
    item() {
        val = a = d = 0;
    }
};
struct lzst {
    ll n;
    item id;
    vector<item> tree;
 
    lzst(ll N) {
        init(N, id);
    }
 
    lzst(ll N, item x) {
        init(N, x);
    }
 
    void init(ll N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, id);
    }
 
    item app(item x, item par, ll range) {
        if(0 == par.d && par.a == 0) {
            return x;
        }
        
        x.val += par.a * range + par.d * (range - 1) * range / 2;
        x.a += par.a;
        x.d += par.d;
 
        return x;
    }
 
    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].a = tree[x].d = 0;
            return;
        }       
 
        tree[2*x] = app(tree[2*x], tree[x], (rx - lx + 1) / 2);
        tree[x].a += tree[x].d * (rx - lx + 1) / 2;
        tree[2*x + 1] = app(tree[2*x + 1], tree[x], (rx - lx + 1) / 2);
 
        tree[x].a = tree[x].d = 0;
    }
 
    void mod(ll x, ll lx, ll rx, ll l, ll r, item v) {
        prop(x, lx, rx);
        if(rx < l || r < lx)
            return;
        if(l <= lx && rx <= r) {
            v.a = v.a + (lx - l) * v.d;
            tree[x] = app(tree[x], v, rx - lx + 1);
            return;
        }
 
        ll d = (lx + rx) / 2;
        mod(2*x, lx, d, l, r, v);
        mod(2*x + 1, d + 1, rx, l, r, v);
 
        tree[x] = merge(tree[2*x], tree[2*x + 1]);
    }
 
    void mod(ll l, ll r, item v) {
        mod(1, 0, n - 1, l, r, v);
    }
 
    ll query(ll x, ll lx, ll rx, ll l, ll r) {
        prop(x, lx, rx);
        if(r < lx || rx < l)
            return 0;
        if(l <= lx && rx <= r)
            return tree[x].val;
        ll d = (lx + rx) / 2;
        return query(2*x, lx, d, l, r) + query(2*x + 1, d + 1, rx, l, r);
    }
 
    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }
 
    item merge(item l, item r) {
        item ans;
        ans.val = l.val + r.val;
        return ans;
    }
};
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    lzst st(n);
    fur(i, 0, n - 1) {
        cin >> st.tree[st.n + i].val;
    }
    ruf(i, st.n - 1, 1) {
        st.tree[i] = st.merge(st.tree[2*i], st.tree[2*i + 1]);
    }
 
    while(m--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll l, r;
            cin >> l >> r;
            --l; --r;
 
            item v;
            v.a = 1;
            v.d = 1;
 
            st.mod(l, r, v);
        } else {
            ll l, r;
            cin >> l >> r;
            --l; --r;
 
            cout << st.query(l, r) << nl;
        }
    }
}
