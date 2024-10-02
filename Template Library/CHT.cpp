// still need to test
// assumes that every new line passed in the method insert will be useful
// ie. some old lines may be removed (from the top of the stack) and then the new line WILL be added
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

    bool better(const Line& L, const pair<Line, int>& M) {
        if(L.m == M.first.m) return L.c <= L.first.c;
        return L.isect(M.first) <= L.second;
    }

    void insert(int m, int c) {
        Line nx = Line(m, c);
        while(!dq.empty() && better(nx, dq.back())) {
            dq.pop_back();
        }
        if(dq.empty()) {
            dq.eb(nx, 0);
        }
        else {
            dq.eb(nx, nx.isect(dq.back().first));
        }
    }

    int query(int x) {
        int m = dq.size();
        while(m > 1 && dq[1].second <= x) {
            dq.pop_front();
            --m;
        }
        return dq.front().first.val(x);
    }

    int query2(int x) {
        int lo = 0;
        int hi = dq.size();
        while(lo + 1 != hi) {
            int mid = (lo + hi) / 2;
            if(dq[mid].second <= x)
                lo = mid;
            else
                hi = mid;
        }
        return dq[lo].first.val(x);
    }
};
