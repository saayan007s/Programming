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

    void mod(int x, int v) {
        x += n;
        a[x] = v;
        for(x /= 2; x > 0; x /= 2) a[x] = a[2*x] + a[2*x + 1];
    }

    int qry(int l, int r) {
        l += n, r += n;
        int res = 0;
        while(l <= r) {
            if(l % 2 == 1) res += a[l++];
            if(r % 2 == 0) res += a[r--];
            l /= 2, r /= 2;
        }
        return res;
    }
};

const int N = 2e5L + 1;
vector<int> adj[N];
int l[N], r[N];
int timer = 1;

void dfs(int x, int p) {
    l[x] = timer++;
    for(int y : adj[x]) {
        if(y != p) dfs(y, x);
    }
    r[x] = timer - 1;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q; cin >> n >> q;
    SegTree st(n + 1);
    int v[n + 1]; for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }

    dfs(1, 0);
    for(int i = 1; i <= n; ++i) {
        st.mod(l[i], v[i]);
    }

    for(int tt = 1; tt <= q; ++tt) {
        int t; cin >> t;
        if(t == 1) {
            int s, x; cin >> s >> x;
            st.mod(l[s], x);
        }
        else {
            int s; cin >> s;
            int res = st.qry(l[s], r[s]);
            cout << res << nl;
        }
    }
}
