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
