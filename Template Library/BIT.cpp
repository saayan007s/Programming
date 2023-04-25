struct BIT {
    int n;
    vector<int> a;

    BIT(int N) {
        n = N - 1;
        a.resize(N);
    }

    void mod(int x, int v) {
        for(; x <= n; x += x&-x) a[x] += v;
    }

    int qry(int x) {
        int res = 0;
        for(;x > 0; x -= x&-x) res += a[x];
        return res;
    }

    int qry(int x, int y) {
        return qry(y) - qry(x - 1);
    }
};

struct FT { // fenwick tree
    vl tree;
    ll n;

    FT(ll N) {
        tree.resize(N);
        n = N - 1;
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
        return res;
    }

    ll qry(ll l, ll r) {
        return qry(r) - qry(l - 1);
    }
};
