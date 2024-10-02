// not well tested
// cses point add, range query
template<typename T>
struct BIT {
    int n;
    vector<T> a;

    BIT(int N) {
        n = N - 1;
        a.resize(N);
    }

    void mod(int x, T v) {
        for(; x <= n; x += x&-x) a[x] += v;
    }

    T qry(int x, int y) {
        T ret = 0;
        for(;y > 0; y -= y&-y) ret += a[y];
        for(--x;x > 0; x -= x&-x) ret -= a[x];
        return ret;
    }

    T qry(int x) {
        return qry(0, x);
    }
};
