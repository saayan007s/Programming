// use the atcoder template
// if the template is hard to understand then just implement all the methods given in atcoder urself
// pass methods to constructor using <> brackets (carrot brackets) 
struct item {
    
};

struct lzst {
    int n;
    item id;
    vector<item> tree;

    lzst(int N) {
        init(N, id);
    }

    lzst(int N, item x) {
        init(N, x);
    }

    void init(int N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, id);
    }

    item app(item x, item p, int range) {
        if() {
            return x;
        }
        
        return x;
    }

    void prop(int x, int lx, int rx) {
        if(lx == rx) {
            tree[x].upd = 0;
            return;
        }       

        tree[2*x] = app(tree[2*x], tree[x], (rx - lx + 1) / 2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x], (rx - lx + 1) / 2);

        tree[x].upd = 0;
    }

    void mod(int x, int lx, int rx, int l, int r, int v) {
        prop(x, lx, rx);
        if(rx < l || r < lx)
            return;
        if(l <= lx && rx <= r) {
            tree[x] = app(tree[x], v, rx - lx + 1);
            return;
        }

        int d = (lx + rx) / 2;
        mod(2*x, lx, d, l, r, v);
        mod(2*x + 1, d + 1, rx, l, r, v);

        tree[x] = merge(tree[2*x], tree[2*x + 1]);
    }

    void mod(int l, int r, int v) {
        mod(1, 0, n - 1, l, r, v);
    }

    item query(int x, int lx, int rx, int l, int r) {
        prop(x, lx, rx);
        if(lx > r || rx < l)
            return id;
        if(lx >= l && rx <= r)
            return tree[x];

        int d = (lx + rx) / 2;
        item a = query(2*x, lx, d, l, r);
        item b = query(2*x + 1, d + 1, rx, l, r);

        return merge(a, b);
    }

    item query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    item merge(item l, item r) {
        item ans;

        return ans;
    }
};
