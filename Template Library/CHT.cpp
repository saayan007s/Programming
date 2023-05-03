// still need to test
struct CHT {
    struct Line {
        int m, c;

        Line(int a, int b) {
            m = a;
            c = b;
        }

        int isect(Line &other) {
            return (c - other.c + other.m - m - 1) / (other.m - m);
        }

        int val(int x) {
            return m*x + c;
        }
    };

    deque<pair<Line, int>> dq;

    void insert(int m, int c) {
        Line nx = Line(m, c);
        if(dq.empty()) {
            dq.eb(nx, 0);
            return;
        }

        while(!dq.empty()) {
            Line pr = dq.back().fr;
            int x = dq.back().sc;
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

    int query(int x) {
        int m = dq.size();
        while(m > 1 && dq[1].sc <= x) {
            dq.pop_front();
            --m;
        }
        return dq.front().fr.val(x);
    }

    int query2(int x) {
        int lo = 0;
        int hi = dq.size();
        while(lo + 1 != hi) {
            int mid = (lo + hi) / 2;
            if(dq[mid].sc <= x)
                lo = mid;
            else
                hi = mid;
        }
        return dq[lo].fr.val(x);
    }
};
