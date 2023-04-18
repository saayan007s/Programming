#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int inf = 1e5L;
struct node {
    int val, mx, mn;

    node() {
        val = 0;
        mx = inf;
        mn = 0;
    }

    node(int t, int h) {
        val = 0;
        mx = inf;
        mn = 0;
        if(t == 2) mx = h;
        else mn = h;
    }
};

struct SegTree {
    int n;
    vector<node> tree;

    SegTree(int N) {
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n);
    }

    node app(node x, node u) {
// here goes nothing
        node res;
        res.val = x.val;
        res.mn = max(x.mn, u.mn);
        res.mx = min(x.mx, u.mx);

        if(res.mn > res.mx) {
            if(res.mn == u.mn) res.mx = u.mn;
            else res.mn = u.mx;
        }

        res.val = min(res.val, res.mx);
        res.val = max(res.val, res.mn);

        return res;
    }

    void prop(int x, int lx, int rx) {
        if(lx == rx) return;

        tree[2*x] = app(tree[2*x], tree[x]);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x]);

        tree[x] = node();
    }

    void mod(int x, int lx, int rx, int l, int r, int h, int t) {
        prop(x, lx, rx);
        if(r < lx || rx < l) return;
        if(l <= lx && rx <= r) {
            node upd(t, h);
            tree[x] = app(tree[x], upd);
            return;
        }

        int d = (lx + rx) / 2;
        mod(2*x, lx, d, l, r, h, t);
        mod(2*x + 1, d + 1, rx, l, r, h, t);
    }

    void mod(int l, int r, int h, int t) {
        mod(1, 0, n - 1, l, r, h, t);
    }

    void prop_all(int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx == rx) return;
        int d = (lx + rx) / 2;
        prop_all(2*x, lx, d);
        prop_all(2*x + 1, d + 1, rx);
    }

    void report(int N) {
        prop_all(1, 0, n - 1);
        for(int i = n; i < n + N; ++i) {
            /* cout << tree[i].val << ' '; */
            cout << tree[i].val << nl;
        }
        /* cout << nl; */
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    SegTree st(n);
    /* cerr << "OK" << nl; */

    for(int tt = 1; tt <= k; ++tt) {
        /* cerr << tt << ' ' << nl; */
        int t, l, r, h;
        cin >> t >> l >> r >> h;
        /* cerr << t << ' ' << l << ' ' << r << ' ' << h << nl << nl; */

        st.mod(l, r, h, t);
        /* st.report(n); */
    }

    st.report(n);
}
