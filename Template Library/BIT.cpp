struct FT { // fenwick tree
    vl tree;

    FT(ll N) {
        tree.resize(N);
    }

    void mod(ll pos, ll val) {
        while(pos <= n) {
            tree[pos] += val;
            pos += pos&-pos;
        }
    }

    ll qry(ll pos) {
        ll res = 0;
        while(pos >= 1) {
            res += tree[pos];
            pos -= pos&-pos;
        }
    }

    ll qry(ll l, ll r) {
        return qry(r) - qry(l - 1);
    }
};
