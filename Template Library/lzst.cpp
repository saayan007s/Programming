struct item {
    
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
        if() {
            return x;
        }
        
        return x;
    }

    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].upd = 0;
            return;
        }       

        tree[2*x] = app(tree[2*x], tree[x], (rx - lx + 1) / 2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x], (rx - lx + 1) / 2);

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

    item query(ll x, ll lx, ll rx, ll l, ll r) {
        prop(x, lx, rx);
        if(lx > r || rx < l)
            return id;
        if(lx >= l && rx <= r)
            return tree[x];

        ll d = (lx + rx) / 2;
        item a = query(2*x, lx, d, l, r);
        item b = query(2*x + 1, d + 1, rx, l, r);

        return merge(a, b);
    }

    item query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }

    item merge(item l, item r) {
        item ans;

        return ans;
    }
};
