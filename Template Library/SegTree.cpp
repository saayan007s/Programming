struct item {
    
}
struct SegTree {
    ll n;
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

    void update(ll pos, item val) {
        pos += n;
        tree[pos] = val;
        pos /= 2;

        while(pos >= 1) {
            tree[pos] = merge(tree[2*pos], tree[2*pos + 1]);
            pos /= 2;
        }
    }

    item query(ll node, ll lo, ll hi, ll ql, ll qh) {
        if(lo > qh || hi < ql)
            return id;
        if(lo >= ql && hi <= qh)
            return tree[node];

        ll mid = (lo + hi) / 2;
        item a = query(2*node, lo, mid, ql, qh);
        item b = query(2*node + 1, mid + 1, hi, ql, qh);

        return merge(a, b);
    }

    item query(ll ql, ll qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    item merge(item l, item r) {
        return l + r;
    }
};
