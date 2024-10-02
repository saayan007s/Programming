// not tested a lot
int sz[];
bool proc[];

void calc_sz(int x, int p) {
    sz[x] = 1;
    for(int y : adj[x]) if(y != p && !proc[y]) {
        calc_sz(y, x);
        sz[x] += sz[y];
    }
}

int find_cen(int x, int p, int f) {
    for(int y : adj[x]) if(y != p && !proc[y]) {
        if(sz[y] * 2 > f) return find_cen(y, x, f);
    }
    return x;
}

void dfs(int x, int p, int h, int i) {
    if(i == ) {
    }
    else if(i == ) {
    }
    else {
    }

    for(int y : adj[x]) if(y != p && !proc[y]) {
        dfs(y, x, h + 1, i);
    }
}

void cd(int x = 1, int p = -1) {
    calc_sz(x, p);
    int c = find_cen(x, p, sz[x]);

    for(int y : adj[c]) if(y != p && !proc[y]) {
        for(int i = 0; i < ; ++i) {
            dfs(y, c, 1, i);
        }
    }

    proc[c] = 1;
    for(int y : adj[c]) if(y != p && !proc[y]) {
        cd(y, c);
    }
}
