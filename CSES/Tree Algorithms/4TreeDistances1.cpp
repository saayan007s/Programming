#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 2e5L + 5;
int n;
vector<int> adj[N];
int mx[N], sm[N];

void dfs(int x, int p) {
    mx[x] = 0, sm[x] = -1;
    for(int y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        if(mx[y] + 1 > mx[x]) {
            sm[x] = mx[x];
            mx[x] = mx[y] + 1;
        }
        else if(mx[y] + 1 > sm[x]) {
            sm[x] = mx[y] + 1;
        }
    }
}

void dfs2(int x, int p) {
    int consider;
    if(mx[p] == mx[x] + 1) {
        consider = sm[p] + 1;
    }
    else consider = mx[p] + 1;
    if(p != 0)
    if(consider > mx[x]) {
        sm[x] = mx[x];
        mx[x] = consider;
    }
    else if(consider > sm[x]) {
        sm[x] = consider;
    }
    for(int y : adj[x]) {
        if(y == p) continue;
        dfs2(y, x);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }

    dfs(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; ++i) cout << mx[i] << ' ';
}
