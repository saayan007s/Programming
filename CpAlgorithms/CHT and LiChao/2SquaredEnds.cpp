#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
const char nl = '\n';

const int inf = 1e15L;
struct node {
    struct Line {
        int m, c;
        Line() {m = 0; c = inf;}
        Line(int a, int b) {m = a; c = b;}
        int val(int x) {return (c < inf ? m*x + c : inf);}
    };

    int s, e, m;
    node *l, *r;
    Line ln;

    node(int a, int b) {
        s = a; e = b;
        m = (s + e) / 2;
        l = NULL; r = NULL;
    }
    void insert(Line nw) {
        bool lef = nw.val(s) < ln.val(s);
        bool mid = nw.val(m) < ln.val(m);
        if(mid) swap(ln, nw);
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
    void insert(int a, int b) {insert(Line(a, b));}

    int qry(int x) {
        int res = ln.val(x);
        if(s == e) return res;
        if(x <= m && l != NULL) res = min(res, l->qry(x));
        else if(x > m && r != NULL) res = min(res, r->qry(x));
        return res;
    }
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    int a[n + 1];
    for(int i = 1; i <= n; ++i) cin >> a[i];

    int dp[n + 1][k + 1] = {};
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i) dp[i][0] = inf;

    for(int j = 1; j <= k; ++j) {
        node root(1, 1000000);
        dp[0][j] = inf;
        for(int i = 1; i <= n; ++i) {
            root.insert(-2*a[i], a[i]*a[i] + dp[i - 1][j - 1]);
            dp[i][j] = root.qry(a[i]) + a[i]*a[i];
        }
    }
    cout << dp[n][k];
}
