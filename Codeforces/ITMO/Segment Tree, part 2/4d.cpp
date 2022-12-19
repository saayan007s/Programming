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
    ll val, wt, upd;    

    item() {
        val = 0;
        wt = 0;
        upd = 0;
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

    item app(item x, ll par, ll range) {
        if(par == 0) {
            return x;
        }

        x.val += par * range;
        x.wt += par * range * (range + 1) / 2;
        x.upd += par;
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

        tree[x] = merge(tree[2*x], tree[2*x + 1], (rx - lx + 1) / 2);
    }

    void mod(ll l, ll r, ll v) {
        mod(1, 0, n - 1, l, r, v);
    }

    ll query(ll x, ll lx, ll rx, ll l, ll r) {
        prop(x, lx, rx);
        if(lx > r || rx < l)
            return 0;
        if(lx >= l && rx <= r)
            return tree[x].wt + tree[x].val * (lx - l);

        ll d = (lx + rx) / 2;
        ll a = query(2*x, lx, d, l, r);
        ll b = query(2*x + 1, d + 1, rx, l, r);

        return a + b;
    }

    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }

    item merge(item l, item r, ll range) {
        item ans;

        ans.val = l.val + r.val;
        ans.wt = l.wt + r.wt + range * r.val;

        return ans;
    }

    void print() {
        fur(i, 1, 2*n - 1) {
            if(__builtin_popcountll(i) == 1)
                cout << nl;
            cout << tree[i].val << '/' << tree[i].wt << ' ';
        }
        cout << nl << nl;
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
        ll a;
        cin >> a;
        st.mod(i, i, a);
    }

    while(m--) {
        ll p;
        cin >> p;
        /* cout << p << ' '; */
        if(p == 1) {
            ll l, r, d;
            cin >> l >> r >> d;
            /* cout << l << ' ' << r << ' ' << d << nl; */
            --l; --r;
            st.mod(l, r, d);
        } else {
            ll l, r;
            cin >> l >> r;
            /* cout << l << ' ' << r << nl; */
            --l; --r;
            cout << st.query(l, r) << nl;
        }
    }
}

