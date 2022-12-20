struct UFDS {
    vl sz;
    vl lnk;

    UFDS(ll N) {
        sz = vl(N + 1, 1);
        lnk = vl(N + 1);
        iota(all(lnk), 0);
    }

    ll find(ll a) {
        return (a == lnk[a] ? a : lnk[a] = find(lnk[a]));
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(sz[a] < sz[b])
            swap(a, b);

        lnk[b] = a;
        sz[a] += sz[b];

        return;
    }
};
