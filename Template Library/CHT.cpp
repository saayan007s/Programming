// still need to test
struct CHT {
    struct Line {
        ll m, c;

        Line(ll a, ll b) {
            m = a;
            c = b;
        }

        ll isect(Line &other) {
            return (c - other.c + other.m - m - 1) / (other.m - m);
        }

        ll val(ll x) {
            return m*x + c;
        }
    };

    deque<pair<Line, ll>> dq;

    void insert(ll m, ll c) {
        Line nx = Line(m, c);
        if(dq.empty()) {
            dq.eb(nx, 0);
            return;
        }

        while(!dq.empty()) {
            Line pr = dq.back().fr;
            ll x = dq.back().sc;
            if(nx.m == pr.m) {
                if(nx.c > pr.c) {
                    return;
                }
            } else if(nx.isect(pr) > x) {
                break;
            }
            dq.pop_back();
        }

        if(dq.empty()) {
            dq.eb(nx, 0);
            return;
        }

        dq.eb(nx, nx.isect(dq.back().fr));
    }

    ll query(ll x) {
        ll m = dq.size();
        while(m > 1 && dq[1].sc <= x) {
            dq.pop_front();
            --m;
        }
        return dq.front().fr.val(x);
    }

    ll query2(ll x) {
        ll lo = 0;
        ll hi = dq.size();
        while(lo + 1 != hi) {
            ll mid = (lo + hi) / 2;
            if(dq[mid].sc <= x)
                lo = mid;
            else
                hi = mid;
        }

        return dq[lo].fr.val(x);
    }
};
