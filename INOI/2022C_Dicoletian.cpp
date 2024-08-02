#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

struct UFDS {
    int n;
    vector<int> lnk, sz;

    UFDS(int N) {
        n = N;
        lnk.resize(n);
        for(int i = 0; i < n; ++i) lnk[i] = i;
        sz.resize(n, 1);
    }

    int find(int a) {
        return (a == lnk[a] ? a : lnk[a] = find(lnk[a]));
    }

    bool same(int a, int b) {
        return (find(a) == find(b));
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        lnk[b] = a;
        sz[a] += sz[b];
    }
};

const int N = 1010, M = 2010;
int n, m, p;
vector<pair<int, bool>> adj[N];
int par[N];
bool vis[N] = {};
int depth[N] = {};
set<pair<int, int>> nt;

void bfs() {
    queue<int> q;
    q.push(1); par[1] = 0; depth[1] = 0; vis[1] = 1;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(auto &[y, b] : adj[x]) {
            if(!vis[y]) {
                q.push(y); par[y] = x; depth[y] = depth[x] + 1;vis[y] = 1;
            }
            else if(y != par[x]) {
                nt.insert({min(x, y), max(x, y)});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;

    for(int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v, 0);
        adj[v].eb(u, 0);
    }

    bfs();

    cout << m << nl;
    for(int i = 2; i <= n; ++i) {
        UFDS uf(n + 1);
        for(int j = 2; j <= n; ++j) {
            if(j == i) continue;
            uf.unite(j, par[j]);
        }
        string res;
        for(int i = 1; i <= n; ++i) {
            if(uf.same(i, 1)) res.push_back('0');
            else res.push_back('1');
        }
        cout << res << nl;
    }

    for(auto [x, y] : nt) {
        UFDS uf(n + 1);
        for(int i = 2; i <= n; ++i) {
            if(i == x || i == y) continue;
            uf.unite(i, par[i]);
        }
        uf.unite(x, y);
        string res;
        for(int i = 1; i <= n; ++i) {
            if(uf.same(i, 1)) res.push_back('0');
            else res.push_back('1');
        }
        cout << res << nl;
    } 
}
