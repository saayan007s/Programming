struct item {
    
};

struct SegTree {
    int n;
    item id;
    vector<item> tree;

    SegTree(int N) {
        init(N, id);
    }

    SegTree(int N, item x) {
        init(N, x);
    }

    void init(int N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, id);
    }

    void update(int x, item val) {
        x += n;
        tree[x] = val;
        x /= 2;

        while(x >= 1) {
            tree[x] = merge(tree[2*x], tree[2*x + 1]);
            x /= 2;
        }
    }

    item query(int x, int lx, int rx, int l, int r) {
        if(lx > r || rx < l)
            return id;
        if(lx >= l && rx <= r)
            return tree[x];

        int d = (lx + rx) / 2;
        item a = query(2*x, lx, d, l, r);
        item b = query(2*x + 1, d + 1, rx, l, r);

        return merge(a, b);
    }

    item query(int ql, int qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    item merge(item l, item r) {
        item ans;
        return ans;
    }
};
