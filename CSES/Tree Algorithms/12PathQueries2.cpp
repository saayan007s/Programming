#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl '\n'
 
struct SegTree {
    int n; vector<int> a;
    SegTree(){}
    SegTree(int M) {
        n = 1; while(n < M) n *= 2;
        a.resize(2*n);
    }
 
    int qry(int l, int r) {
        l += n; r += n;
        int res = 0;
        while(l <= r) {
            if(l % 2 == 1) res = max(res, a[l++]);
            if(r % 2 == 0) res = max(res, a[r--]);
            l /= 2; r /= 2;
        }
        return res;
    }
 
    void mod(int x, int v) {
        x += n;
        a[x] = v;
        x /= 2;
        while(x >= 1) {
            a[x] = max(a[2*x], a[2*x + 1]);
            x /= 2;
        }
    }
};
 
const int N = 2e5L + 1;
const int logn = 20;
int n;
vector<int> adj[N];
int wt[N], depth[N], par[N][logn], cnt[N];
int head[N], chid[N], pos[N];
int ptr = 0, cur_id = 0;
SegTree st;
 
void hld(int x, int p) {
    int h = 0;
    pos[x] = ptr++;
    chid[x] = cur_id;
    for(auto y : adj[x]) {
        if(y == p) continue;
        if(h == 0 || cnt[h] < cnt[y]) h = y;
    }
    if(h == 0) return;
    hld(h, x); 
    for(auto y : adj[x]) {
        if(y == p || y == h) continue;
        ++cur_id;
        head[cur_id] = y;
        hld(y, x);
    }
}
 
void dfs(int x, int p) {
    par[x][0] = p;
    cnt[x] = 1;
    for(auto y : adj[x]) {
        if(y == p) continue;
        depth[y] = depth[x] + 1;
        dfs(y, x);
        cnt[x] += cnt[y];
    }
}
 
void precompute() {
    depth[1] = 0;
    dfs(1, 0);
    for(int j = 1; j < logn; ++j) {
        for(int i = 1; i <= n; ++i) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
 
void modify(int x, int v) {
    wt[x] = v;
    st.mod(pos[x], wt[x]);
}
 
int lca(int a, int b) {
    if(a == b) return a;
    if(depth[a] > depth[b]) swap(a, b);
    int diff = depth[b] - depth[a];
    for(int j = logn - 1; j >= 0; --j) {
        if(diff & (1LL << j)) {
            b = par[b][j];
        }
    }
    if(a == b) return a;
    for(int j = logn - 1; j >= 0; --j) {
        if(depth[a] > (1LL << j) && par[a][j] != par[b][j]) {
            a = par[a][j];
            b = par[b][j];
        }
    }
    return par[a][0];
}
 
int query(int a, int b) {
    int c = lca(a, b);
    int res = 0;
 
    while(head[chid[a]] != head[chid[c]]) {
        res = max(res, st.qry(pos[head[chid[a]]], pos[a]));
        a = par[head[chid[a]]][0];
    }
    res = max(res, st.qry(pos[c], pos[a]));
 
    while(head[chid[b]] != head[chid[c]]) {
        res = max(res, st.qry(pos[head[chid[b]]], pos[b]));
        b = par[head[chid[b]]][0];
    }
    res = max(res, st.qry(pos[c], pos[b]));
 
    return res;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int qu;
    cin >> n >> qu;
    for(int i = 1; i <= n; ++i) cin >> wt[i];
 
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }
    precompute();
    head[0] = 1;
    hld(1, 0);
 
    st = SegTree(n);
    for(int i = 1; i <= n; ++i) {
        st.a[st.n + pos[i]] = wt[i];
    }
    for(int i = st.n - 1; i > 0; --i) {
        st.a[i] = max(st.a[i*2], st.a[i*2 + 1]);
    }
 
    for(int tt = 1; tt <= qu; ++tt) {
        int ty; cin >> ty;
        if(ty == 2) {
            int a, b; cin >> a >> b;
            int res = query(a, b);
            cout << res << " ";
        }
        else {
            int i, v; cin >> i >> v;
            modify(i, v);
        }
    }
}
