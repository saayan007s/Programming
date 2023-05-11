#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 2e5L + 1;
vector<int> adj[N];
int in[N], ex[N], best[N];

void dfs(int x, int p) {
    in[x] = ex[x] = 0;
    int opt = -1e18;

    for(int y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        ex[x] += best[y];
        in[x] += best[y];
        opt = max(opt, ex[y] - best[y] + 1);
    }
    in[x] += opt;
    best[x] = max(in[x], ex[x]);
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }

    dfs(1, 0);
    cout << best[1];
}
