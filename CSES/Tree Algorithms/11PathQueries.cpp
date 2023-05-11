#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

struct SegTree {
    int n;
    vector<int> a;

    SegTree(int N) {
        n = 1;
        while(n < N) n *= 2;
        a.resize(2*n);
    }

    void mod(int l, int r, int v) {
        l += n, r += n;
        while(l <= r) {
            if(l % 2 == 1) a[l++] = max(a[l], v);
            if(r % 2 == 0) a[r--] = max(a[r], v);
            l /= 2, r /= 2;
        }
    }

    int qry(int x) {
        int res = 0;
        for(x += n; x > 0; x /= 2) res = max(res, a[x]);
        return res;
    }
};

const int N = 2e5L + 1;
vector<int> adj[N];
int l[N], r[N], v[N];
int timer = 1;
SegTree st(N);

void dfs(int x, int p) {
    l[x] = timer++;
    st.a[l[x] + st.n] = max(st.a[l[p] + st.n], v[x]);
    for(int y : adj[x]) {
        if(y != p) dfs(y, x);
    }
    r[x] = timer - 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }

    dfs(1, 0);

    for(int tt = 1; tt <= q; ++tt) {
        int t; cin >> t;
        if(t == 1) {
            int s, x; cin >> s >> x;
            st.mod(l[s], r[s], x);
        }
        else {
            int s; cin >> s;
            int res = st.qry(l[s]);
            cout << res << nl;
        }
    }
}
