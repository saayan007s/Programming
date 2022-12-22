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

using item = pair<long long, long long>;
#define val first
#define upd second
const ll inf = 1e18;

struct lzst {
    ll n;
    item id = {0ll, -1ll};
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

    pl app(pl a, ll b, ll range) {
        if(b == -1)
            return a;
        a.val = b;
        a.upd = b;
        return a;
    }

    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].upd = -1;
            return;
        }
        tree[2*x] = app(tree[2*x], tree[x].upd, (rx - lx + 1)/2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x].upd, (rx - lx + 1)/2);

        // update tree[x]
        tree[x].upd = -1;
        tree[x].val = min(tree[2*x].val, tree[2*x + 1].val);
    }

    void mod(ll x, ll lx, ll rx, ll l, ll r, ll v) {
        prop(x, lx, rx);
        if(r < lx || rx < l)
            return;
        if(l <= lx && rx <= r) {
            tree[x] = app(tree[x], v, rx - lx + 1);
            return;
        }

        ll mid = (lx + rx) / 2;
        mod(2*x, lx, mid, l, r, v);
        mod(2*x + 1, mid + 1, rx, l, r, v);

        tree[x].val = min(tree[2*x].val, tree[2*x + 1].val);
    }

    void mod(ll l, ll r, ll v) {
        mod(1, 0, n - 1, l, r, v);
    }

    ll comb(ll a, ll b) {
        return min(a, b);
    }
    ll query(ll x, ll lx, ll rx, ll l, ll r) {
        prop(x, lx, rx);
        if(r < lx || rx < l)
            return inf;
        if(l <= lx && rx <= r)
            return tree[x].val;

        ll res = inf;

        ll mid = (lx + rx) / 2;

        res = comb(res, query(2*x, lx, mid, l, r));
        res = comb(res, query(2*x + 1, mid + 1, rx, l, r));

        return res;
    }

    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);  
    }

    void print() {
        fur(i, 1, 2*n - 1) {
            if(__builtin_popcountll(i + 1) == 1)
                cout << nl;
        }
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
        ll op, l, r;
        cin >> op >> l >> r;
        --r;
        if(op == 1) {
            ll v;
            cin >> v;
            st.mod(l, r, v);
        } else {
            cout << st.query(l, r) << nl;
        }
    }
}

