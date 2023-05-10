#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
const char nl = '\n';

const int inf = 1e19L;
const int A = 1e6L;
struct Line {
    int m, c;
    Line() {m = 0; c = -inf;}
    Line(int a, int b) {m = a; c = b;}
    int val(int x) {return m*x + c;}
};

struct node {
    int s, m, e;
    node *l, *r;
    Line ln;

    node(int _s, int _e) {
        s = _s; e = _e;
        m = (s + e) / 2;
        l = NULL; r = NULL;
    }

    void insert(Line nw) {
        bool lef = nw.val(s - A) > ln.val(s - A);
        bool mid = nw.val(m - A) > ln.val(m - A);
        if(mid) {
            int tmpm = ln.m; int tmpc = ln.c;
            ln.m = nw.m; ln.c = nw.c;
            nw.m = tmpm; nw.c = tmpc;
        }
        if(s == e) return;
        if(lef ^ mid) {
            if(l == NULL) l = new node(s, m);
            l->insert(nw);
        }
        else {
            if(r == NULL) r = new node(m + 1, e);
            r->insert(nw);
        }
    }

    int qry(int x) {
        int res = ln.val(x - A);
        if(s == e) return res;
        if(x <= m && l != NULL) res = max(res, l->qry(x));
        else if(r != NULL) res = max(res, r->qry(x));
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n + 1], s[n + 1];
    a[0] = s[0] = 0;
    int sum = 0;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
        sum += a[i] * i;
    }

    int res = 0;
    node forw(0, 2*A);
    forw.insert(Line(n, -s[n]));
    for(int i = n - 1; i > 0; --i) {
        int opt = forw.qry(A + a[i]);
        opt = opt + s[i] - a[i]*i;
        if(res < opt) res = opt;
        forw.insert(Line(i, -s[i]));
    }

    node back(0, 2*A);
    back.insert(Line(1, -s[0]));
    for(int i = 2; i <= n; ++i) {
        int opt = back.qry(A + a[i]);
        opt = opt + s[i - 1] - a[i]*i;
        if(res < opt) res = opt;
        back.insert(Line(i, -s[i - 1]));
    }

    cout << sum + res << nl;
}
