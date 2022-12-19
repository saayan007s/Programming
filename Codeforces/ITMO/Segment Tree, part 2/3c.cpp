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

using item = pair<long long, long long>;
#define val first
#define upd second

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

    item app(item x, ll ch, ll range) {
        x.val += ch;
        x.upd += ch;
        return x;
    }

    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].upd = 0;
            return;
        }       

        tree[2*x] = app(tree[2*x], tree[x].upd, (rx - lx + 1) / 2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x].upd, (rx - lx + 1) / 2);

        tree[x].upd = 0;
    }

    void mod(ll x, ll lx, ll rx, ll l, ll r, ll v) {
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

        tree[x] = merge(tree[2*x], tree[2*x + 1]);
    }

    void mod(ll l, ll r, ll v) {
        mod(1, 0, n - 1, l, r, v);
    }

    ll query(ll x, ll lx, ll rx, ll y, ll l) {
        prop(x, lx, rx);
        if(lx == rx)
            return tree[x].val >= y ? lx : n + 1;
        if(rx < l)
            return n + 1;
        ll d = (lx + rx) / 2;
        if(lx < l) {
            ll a = n + 1;
            if(l <= d)
                a = query(2*x, lx, d, y, l);
            
            ll b = query(2*x + 1, d + 1, rx, y, l);
            
            return min(a, b);
        }

        if(tree[2*x].val >= y)
            return query(2*x, lx, d, y, l);
        else if(tree[2*x + 1].val >= y)
            return query(2*x + 1, d + 1, rx, y, l);
        return n + 1;
    }

    ll query(ll y, ll l) {
        return query(1, 0, n - 1, y, l);
    }

    item merge(item l, item r) {
        item ans;
        ans.val = max(l.val, r.val);
        ans.upd = 0;
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
    while(m--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            st.mod(l, r - 1, v);
        } else {
            ll x, l;
            cin >> x >> l;
            ll ans = st.query(x, l); 
            cout << (ans >= n ? -1 : ans) << nl;
        }
        
        /* st.print(); */
    }
}

