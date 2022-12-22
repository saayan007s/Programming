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
    item id = {0ll, 0ll};
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
        tree = vector<item>(2*n, id);
    }

    item app(item x, ll ch, ll range) {
        if(ch == 0) {
            return x;
        }
        
        x.val = range - x.val;
        x.upd = 1 - x.upd;
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

    void mod(ll x, ll lx, ll rx, ll l, ll r) {
        prop(x, lx, rx);
        if(rx < l || r < lx)
            return;
        if(l <= lx && rx <= r) {
            tree[x] = app(tree[x], 1, rx - lx + 1);
            return;
        }

        ll d = (lx + rx) / 2;
        mod(2*x, lx, d, l, r);
        mod(2*x + 1, d + 1, rx, l, r);

        tree[x] = merge(tree[2*x], tree[2*x + 1]);
    }

    void mod(ll l, ll r) {
        mod(1, 0, n - 1, l, r);
    }

    ll query(ll x, ll lx, ll rx, ll k) {
        prop(x, lx, rx);
        if(lx == rx)
            return lx;

        ll d = (lx + rx) / 2;

        if(tree[2*x].val >= k)
            return query(2*x, lx, d, k);
        return query(2*x + 1, d + 1, rx, k - tree[2*x].val);
    }

    ll query(ll k) {
        return query(1, 0, n - 1, k);
    }

    item merge(item l, item r) {
        item ans;
        ans.val = l.val + r.val;
        ans.upd = 0;
        return ans;
    }

    /* void print() { */
    /*     fur(i, 1, 2*n - 1) { */
    /*         if(__builtin_popcountll(i) == 1) */
    /*             cout << nl; */
    /*         cout << tree[i].val << '/' << tree[i].upd << ' '; */
    /*     } */
    /*     cout << nl; */
    /* } */
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
            ll l, r;
            cin >> l >> r;
            st.mod(l, r - 1);
        } else {
            ll k;
            cin >> k;
            cout << st.query(++k) << nl;
        }
        
        /* st.print(); */
    }
}

