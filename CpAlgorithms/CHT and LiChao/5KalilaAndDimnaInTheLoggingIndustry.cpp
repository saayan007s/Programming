#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int inf = 1e19L;
struct Line {
    int m, c;
    Line() {m = 0; c = inf;}
    Line(int a, int b) {m = a; c = b;}
    int val(int x) {return m*x + c;}
};

struct node {
    int s, e, m;
    Line ln;
    node *l, *r;

    node(int a, int b) {
        s = a; e = b;
        m = (s + e) / 2;
        l = NULL; r = NULL;
    }

    void insert(Line nw) {
        bool mid = nw.val(m) < ln.val(m);
        bool lef = nw.val(s) < ln.val(s);
        if(mid) {
            swap(nw, ln);
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
        int res = ln.val(x);
        if(s == e) return res;
        if(x <= m && l != NULL) {
            res = min(res, l->qry(x));
        }
        else if(r != NULL) {
            res = min(res, r->qry(x));
        }
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n], b[n];
    for(int &i : a) cin >> i;
    for(int &i : b) cin >> i;
    int dp[n]; dp[0] = 0;
    node root(1, 1000000000);
    root.insert(Line(b[0], dp[0]));
    for(int i = 1; i < n; ++i) {
        dp[i] = root.qry(a[i]);
        root.insert(Line(b[i], dp[i]));
    }
    cout << dp[n - 1] << nl;
}
