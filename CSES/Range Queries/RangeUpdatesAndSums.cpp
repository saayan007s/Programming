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
    ll val, ass, add;    
 
    item() {
        val = 0;
        ass = -1;
        add = 0;
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
        if(par.ass == -1 && par.add == 0) {
            return x;
        }
        
        if(par.ass != -1) {
            x.ass = par.ass;
            x.add = 0;
            x.val = range * par.ass;
        } else {
            x.val += range * par.add;
 
            if(x.ass != -1) {
                x.ass += par.add;
            }
            else {
                x.add += par.add;
            }
        }
        return x;
    }
 
    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].ass = -1;
            tree[x].add = 0;
            return;
        }       
 
        tree[2*x] = app(tree[2*x], tree[x], (rx - lx + 1) / 2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x], (rx - lx + 1) / 2);
 
        tree[x].ass = -1;
        tree[x].add = 0;
    }
 
    void mod(ll x, ll lx, ll rx, ll l, ll r, item v) {
        prop(x, lx, rx);
        if(rx < l || r < lx)
            return;
        if(l <= lx && rx <= r) {
            tree[x] = app(tree[x], v, rx - lx + 1);
            return;
        }
 
        ll d = (lx + rx) / 2;
        mod(2*x, lx, d, l, r, v);
        mod(2*x + 1, d + 1, rx, l, r, v);
 
        tree[x].val = tree[2*x].val + tree[2*x + 1].val;
    }
 
    void mod(ll l, ll r, item v) {
        mod(1, 0, n - 1, l, r, v);
    }
 
    ll query(ll x, ll lx, ll rx, ll l, ll r) {
        prop(x, lx, rx);
        if(lx > r || rx < l)
            return 0;
        if(lx >= l && rx <= r)
            return tree[x].val;
 
        ll d = (lx + rx) / 2;
        ll a = query(2*x, lx, d, l, r);
        ll b = query(2*x + 1, d + 1, rx, l, r);
 
        return a + b;
    }
 
    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }
 
    void print() {
        fur(i, 1, 2*n - 1) {
            if(__builtin_popcountll(i) == 1)
                cout << nl;
            cout << tree[i].val << '/' << tree[i].ass << '/' << tree[i].add << "  ";
        }
        cout << nl;
    }
};
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    lzst st(n);
    fur(i, st.n, st.n + n - 1) {
        cin >> st.tree[i].val;
    }
    ruf(i, st.n - 1, 1)
        st.tree[i].val = st.tree[2*i].val + st.tree[2*i + 1].val;
 
    while(m--) {
        ll op, l, r;
        cin >> op >> l >> r;
        --l;
        --r;
        if(op == 1) {
            ll v;
            cin >> v;
            item q;
            q.ass = -1;
            q.add = v;
            q.val = 0;
            st.mod(l, r, q);
        } else if(op == 2) {
            ll v;
            cin >> v;
            item q;
            q.ass = v;
            q.add = 0;
            q.val = 0;
            st.mod(l, r, q);
        } else if(op == 3) {
            cout << st.query(l, r) << nl;
        }
 
        /* st.print(); */
    }
}
 
