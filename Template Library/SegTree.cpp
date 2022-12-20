struct item {
    
};

struct SegTree {
    ll n;
    item id;
    vector<item> tree;

    SegTree(ll N) {
        init(N, id);
    }

    SegTree(ll N, item x) {
        init(N, x);
    }

    void init(ll N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, id);
    }

    void update(ll x, item val) {
        x += n;
        tree[x] = val;
        x /= 2;

        while(x >= 1) {
            tree[x] = merge(tree[2*x], tree[2*x + 1]);
            x /= 2;
        }
    }

    item query(ll x, ll lx, ll rx, ll l, ll r) {
        if(lx > r || rx < l)
            return id;
        if(lx >= l && rx <= r)
            return tree[x];

        ll d = (lx + rx) / 2;
        item a = query(2*x, lx, d, l, r);
        item b = query(2*x + 1, d + 1, rx, l, r);

        return merge(a, b);
    }

    item query(ll ql, ll qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    item merge(item l, item r) {
        item ans;
        return ans;
    }
};
