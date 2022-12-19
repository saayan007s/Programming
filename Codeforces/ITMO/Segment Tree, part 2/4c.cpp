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
    ll val, upd, seg;
    bool l, r;

    item() {
        val = 0;
        l = 0;
        r = 0;
        upd = -1;
        seg = 0;
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

    item app(item x, ll ch, ll range) {
        if(ch == -1) {
            return x;
        }
        
        if(ch == 1) {
            x.val = range;
            x.l = x.r = 1;
            x.upd = 1;
            x.seg = 1;
        } else {
            x.val = 0;
            x.l = x.r = 0;
            x.upd = 0;
            x.seg = 0;
        }
        return x;
    }

    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].upd = -1;
            return;
        }       

        tree[2*x] = app(tree[2*x], tree[x].upd, (rx - lx + 1) / 2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x].upd, (rx - lx + 1) / 2);

        tree[x].upd = -1;
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

    item merge(item lhs, item rhs) {
        item ans;
        ans.l = lhs.l;
        ans.r = rhs.r;
        ans.val = lhs.val + rhs.val;
        ans.seg = lhs.seg + rhs.seg - (lhs.r && rhs.l ? 1 : 0);
        return ans;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    lzst st(2000001);

    fur(test, 1, n) {
        char c;
        cin >> c;
        ll l, r;
        cin >> l >> r;
        r += l - 1;

        l += 500000;
        r += 500000;

        ll v = (c == 'B' ? 1 : 0);

        st.mod(l, r, v);

        cout << st.tree[1].seg << ' ' << st.tree[1].val << nl;
    }
}

