struct UFDS {
    int n; vector<int> lnk, sz;

    UFDS(int N) {
        n = N;
        lnk.resize(N); iota(lnk.begin(), lnk.end(), 0);
        sz.resize(N);
    }

    int find(int a) {
        return (a == lnk[a] ? a : lnk[a] = find(lnk[a]));
    }

    bool same(int a, int b) {
        return (find(a) == find(b));
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        lnk[b] = a;
        sz[a] += sz[b];
        return;
    }
};
