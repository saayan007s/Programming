#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
const char nl = '\n';

const int inf = 1e19L;
struct Line {
    int m, c;
    Line() {m = 0; c = -inf;}
    Line(int a, int b) {m = a; c = b;}
    int val(int x) {return m*x + c;}
    int isect(Line &other) {
        return (other.c - c + m - other.m - 1) / (m - other.m);
    }
};

struct CHT {
    deque<pair<Line, int>> dq;

    void insert(Line nw) {
        if(dq.empty()) {
            dq.eb(nw, -inf);
            return;
        }
        Line ln = dq.back().fr;
        int x = dq.back().sc;
        while(!dq.empty() && ln.isect(nw) <= x) {
            dq.pop_back();
            ln = dq.back().fr;
            x = dq.back().sc;
        }
        if(dq.empty()) {
            dq.eb(nw, -inf);
            return;
        }
        dq.eb(nw, nw.isect(dq.back().fr));
    }

    int qry(int x) {
        int lo = 0, hi = dq.size();
        while(lo + 1 != hi) {
            int d = (lo + hi) / 2;
            (dq[d].sc <= x ? lo : hi) = d;
        }
        return dq[lo].fr.val(x);
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    int x[n + 1], p[n + 1];
    p[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
        p[i] = x[i] + p[i - 1];
    }

    CHT cht;
    int dp[n + 1]; dp[0] = 0;
    for(int i = 1; i <= n; ++i) {
        cht.insert(Line(p[i-1], a*p[i-1]*p[i-1] - b*p[i-1] + dp[i-1]));
        dp[i] = cht.qry(-2*a*p[i]) + a*p[i]*p[i] + b*p[i] + c;
    }
    cout << dp[n];
}
