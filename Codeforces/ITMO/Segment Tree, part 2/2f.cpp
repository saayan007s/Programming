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

    pl app(pl a, ll b, ll c) {
        if(b == -1)
            return a;
        a.val = b * c;
        a.upd = b;

        return a;
    }

    void prop(ll node, ll l, ll r) {
        if(l == r) {
            tree[node].upd = -1;
            return;
        }
        tree[2*node] = app(tree[2*node], tree[node].upd, (r - l + 1) / 2);
        tree[2*node + 1] = app(tree[2*node + 1], tree[node].upd, (r - l + 1) / 2);

        // update tree[node]
        tree[node].upd = -1;
    }

    void mod(ll node, ll lo, ll hi, ll l, ll r, ll v) {
        prop(node, lo, hi);
        if(r < lo || hi < l)
            return;
        if(l <= lo && hi <= r) {
            prop(node, lo, hi);
            tree[node] = app(tree[node], v, hi - lo + 1);
            // code here
            for(node /= 2; node >= 1; node /= 2) {
                tree[node].val = tree[2*node].val + tree[2*node + 1].val;
            }
            return;
        }

        ll mid = (lo + hi) / 2;
        mod(2*node, lo, mid, l, r, v);
        mod(2*node + 1, mid + 1, hi, l, r, v);
    }

    void mod(ll l, ll r, ll v) {
        mod(1, 0, n - 1, l, r, v);
    }

    ll comb(ll a, ll b) {
        return a + b;
    }
    ll query(ll node, ll lo, ll hi, ll l, ll r) {
        prop(node, lo, hi);
        if(r < lo || hi < l)
            return 0;
        if(l <= lo && hi <= r)
            return tree[node].val;

        ll res = 0;
        ll mid = (lo + hi) / 2;
        res = comb(res, query(2*node, lo, mid, l, r));
        res = comb(res, query(2*node + 1, mid + 1, hi, l, r));

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
        ll op;
        cin >> op;
        if(op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            st.mod(l, r - 1, v);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << st.query(l, r - 1) << nl;
        }
    }
}
