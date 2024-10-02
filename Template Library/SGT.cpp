// test on initial cses problems
// currently not working correctly
// TODO: pass combine as argument into constructor, like SGT<int, combine> sgt
// make mod interval and qry point in addition to what is already there

template<typename T, T (*combine)(const T&, const T&)>
struct SGT {
    int n;
    T id;
    vector<T> tr;

    SGT(int N) {
        n = 1; while(n < N) n *= 2;
        tr.resize(2*n, id);
    }

    SGT(int N, T x) {
        id = x;
        n = 1; while(n < N) n *= 2;
        tr.resize(2*n, id);
    }

    SGT(vector<T> x) {
        n = 1; while(n < x.size()) n *= 2;
        for(int i = 0; i < x.size(); ++i) {
            tr[i + n] = x[i];
        }
        for(int i = n - 1; i > 0; --i) {
            calc(i);
        }
    }

    void calc(int x) {
        if(x >= n) return;
        tr[x] = combine(tr[2*x], tr[2*x + 1]);
    }

    void mod1(int x, T v) {
        // first call to calc is for some x >= n
        for(tr[x += n] = v; x > 0; x /= 2) {
            calc(x);
        }
    }

    void mod2(int x, int lx, int rx, int l, int r, T v) {
        if(lx > r || rx < l) {
            return;
        }
        if(lx >= l && rx <= r) {
            tr[x] = v;
            return;
        }

        int d = (lx + rx) / 2;
        mod2(2*x, lx, d, l, r, v);
        mod2(2*x + 1, d + 1, rx, l, r, v);
    }

    void mod2(int l, int r, T v) {
        mod2(1, 0, n - 1, l, r, v);
    }

    T qry1(int i) {
        T ret = id;
        for(i += n; i > 0; i /= 2) {
            ret = combine(ret, tr[i]);
        }
        return ret;
    }

    T qry2(int x, int lx, int rx, int l, int r) {
        if(lx > r || rx < l) {
            return id;
        }
        if(lx >= l && rx <= r) {
            return tr[x];
        }

        int d = (lx + rx) / 2;
        T a = qry2(2*x, lx, d, l, r);
        T b = qry2(2*x + 1, d + 1, rx, l, r);
        return combine(a, b);
    }

    T qry2(int l, int r) {
        return qry2(1, 0, n - 1, l, r);
    }
};
