#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
const char nl = '\n';
const int inf = 1e18L + 1;

struct node {
    int s, e, m;
    node *l, *r;
    int val, lz;

    node() {}
    node(int _s, int _e) {
        s = _s; e = _e; m = (s + e) / 2;
        val = 0; lz = 0;
        if(s != e) { l = new node(s, m); r = new node(m + 1, e); }
    }

    void prop() {
        if(s != e) {
            r->lz += lz; r->val += lz;
            l->lz += lz; l->val += lz;
        }
        lz = 0;
    }

    int qry(int a, int b) {
        prop();
        if(e < a || b < s) return inf;
        if(a <= s && e <= b) return val;
        return min(l->qry(a, b), r->qry(a, b));
    }

    void mod(int a, int b, int v) {
        prop();
        if(e < a || b < s) return;
        if(a <= s && e <= b) {
            lz += v; val += v;
            return;
        }
        l->mod(a, b, v); r->mod(a, b, v);
        val = min(l->val, r->val);
    }

    bool done() {
        prop();
        return val > 0;
    }
};

const int N = 1e5L + 5;
int n, m;
vector<int> adj[N];
int sz[N], depth[N], head[N], pos[N], par[N];
int tim = 0;
node root;

void dfs(int x, int p) {
    sz[x] = 1;
    for(int y : adj[x]) {
        if(y == p) continue;
        depth[y] = depth[x] + 1;
        par[y] = x;
        dfs(y, x);
        sz[x] += sz[y];
    }
}

void hld(int x, int h, int p) {
    pos[x] = tim++;
    head[x] = h;
    int g = 0;
    for(int y : adj[x]) {
        if(y == p) continue;
        if(g == 0 || sz[g] < sz[y]) g = y;
    }

    if(g != 0) hld(g, h, x);
    for(int y : adj[x]) {
        if(y == p || y == g) continue;
        hld(y, y, x);
    }
}

void precompute() {
    depth[1] = 0;
    par[1] = 0;
    dfs(1, 0);
    hld(1, 1, 0);
}

void add_edge(int a, int b, int v) {
    while(head[a] != head[b]) {
        if(depth[head[a]] < depth[head[b]]) swap(a, b);
        root.mod(pos[head[a]], pos[a], v);
        a = par[head[a]];
    }
    if(pos[a] > pos[b]) swap(a, b);
    root.mod(pos[a] + 1, pos[b], v);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v);
        adj[v].eb(u);
    }
    m = m - (n - 1);
    vector<vector<int>> edge;
    for(int i = 0; i < m; ++i) {
        int a, b, w; cin >> a >> b >> w;
        edge.push_back({w, a, b});
    }

    precompute();
    for(auto &vec : edge) {
        if(depth[vec[1]] > depth[vec[2]]) swap(vec[1], vec[2]);
    }
    sort(edge.rbegin(), edge.rend());

    set<vector<int>, greater<vector<int>>> used;
    root = node(1, n - 1);
    int ans = -1;
    for(auto vec : edge) {
        int a = vec[1], b = vec[2], c = vec[0];
        add_edge(a, b, 1);
        used.insert({c, a, b});
        if(root.done()) {
            ans = c;
            break;
        }
    }

    cout << ans << nl;
    int qu; cin >> qu;
    while(qu--) {
        int a, b, c; cin >> a >> b >> c;
        if(ans > c) {
            cout << ans << nl;
            continue;
        }
        add_edge(a, b, 1);
        used.insert({c, a, b});
        if(!root.done()) {
            cout << -1 << nl;
            continue;
        }
        while(root.done()) {
            auto ptr = used.end();
            --ptr;
            a = (*ptr)[1], b = (*ptr)[2], c = (*ptr)[0];
            add_edge(a, b, -1);
            used.erase(ptr);
        }
        ans = c;
        add_edge(a, b, 1);
        used.insert({c, a, b});
        cout << ans << nl;
    }
}
