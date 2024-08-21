// not tested well
// cses lca queries
vector<int> adj[];
int par[], dep[], sz[], head[], pos[];
int timer;

int dfs(int x = 1, int p = 0) {
    par[x] = p;
    sz[x] = 1;
    for(int y : adj[x]) {
        if(y == p) continue;
        dep[y] = dep[x] + 1;
        sz[x] += dfs(y, x);
    }
    return sz[x];
}

void build(int x = 1, int p = 0, int h = 1) {
    head[x] = h;
    pos[x] = timer++;
    int g = 0;
    for(int y : adj[x]) {
        if(y == p) continue;
        if(g == 0 || sz[g] < sz[y]) g = y;
    }

    if(g != 0) build(g, x, h);
    for(int y : adj[x]) {
        if(y == p || y == g) continue;
        build(y, x, y);
    }
}

void decompose() {
    timer = 1;
    dep[1] = 0;
    dfs();
    build();
}

int lca(int a, int b) {
    while(head[a] != head[b]) {
        if(dep[head[a]] < dep[head[b]]) swap(a, b);
        a = par[head[a]];
    }
    return (dep[a] < dep[b] ? a : b);
}
