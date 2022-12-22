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


using item = pl;
#define val first
#define mul second
const ll mod = 1e9 + 7;

ll tim(ll a, ll b) {
    a %= mod;
    b %= mod;

    a *= b;
    a %= mod;
    if(a < 0)
        a += mod;
    return a;
}

ll sum(ll a, ll b) {
    a %= mod;
    b %= mod;

    a += b;
    a %= mod;
    if(a < 0)
        a += mod;
    return a;
}

struct lzst {
    ll n;
    item id = {0ll, 1ll};
    vector<item> tree;

    lzst(ll N) {
        init(N, id);
    }

    void init(ll N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1)
            ++n;

        tree.resize(2*n, id);

        fur(i, 0, N - 1)
            tree[n + i].val = 1;
        ruf(i, n - 1, 1)
            tree[i].val = sum(tree[2*i].val, tree[2*i + 1].val);
    }

    pl app(pl a, ll b) {
        a.mul = tim(a.mul, b);
        a.val = tim(a.val, b);

        return a;
    }

    void prop(ll node, ll l, ll r) {
        if(l == r) {
            tree[node].mul = 1;
            return;
        }
        tree[2*node] = app(tree[2*node], tree[node].mul);
        tree[2*node + 1] = app(tree[2*node + 1], tree[node].mul);

        // update tree[node]
        tree[node].mul = 1;
    }

    void mod(ll node, ll lo, ll hi, ll l, ll r, ll v) {
        prop(node, lo, hi);
        if(r < lo || hi < l)
            return;
        if(l <= lo && hi <= r) {
            tree[node] = app(tree[node], v);
            return;
        }

        ll mid = (lo + hi) / 2;
        mod(2*node, lo, mid, l, r, v);
        mod(2*node + 1, mid + 1, hi, l, r, v);
        tree[node].val = sum(tree[2*node].val, tree[2*node + 1].val);
    }

    void mod(ll l, ll r, ll v) {
        mod(1, 0, n - 1, l, r, v);
    }

    ll query(ll node, ll lo, ll hi, ll l, ll r) {
        prop(node, lo, hi);
        if(r < lo || hi < l)
            return 0;
        if(l <= lo && hi <= r)
            return tree[node].val;

        ll res = 0;
        ll mid = (lo + hi) / 2;
        res = sum(res, query(2*node, lo, mid, l, r));
        res = sum(res, query(2*node + 1, mid + 1, hi, l, r));

        return res;
    }

    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);  
    }

    void print() {
        fur(i, 1, 2*n - 1) {
            cout << tree[i].val << '/' << tree[i].mul << ' ';
            if(__builtin_popcountll(i + 1) == 1)
                cout << nl;
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
    while(m--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            --r;
            st.mod(l, r, v);
        } else {
            ll l, r;
            cin >> l >> r;
            // if(m == 4)
                // cout << l << ' ' << r << nl;
            --r;
            cout << st.query(l, r) << nl;
        }
        // if(m == 4)
            // st.print();
    }
}

