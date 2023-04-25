include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int inf = 1e18L;
const int N = 5e5L + 10;
const int logn = 20;
int n, q;
int v[N];
int par[N][logn];
int dp[N][logn][4];
int depth[N];
vector<int> adj[N];

void dfs(int x) {
    dp[x][0][0] = 0;
    dp[x][0][1] = v[par[x][0]];
    dp[x][0][2] = v[x];
    dp[x][0][3] = max(v[x], v[par[x][0]]);
    for(int y : adj[x]) {
        if(y == par[x][0]) continue;
        par[y][0] = x;
        depth[y] = depth[x] + 1;
        dfs(y);
    }
}

void precompute() {
    for(int i = 0; i < logn; ++i) par[1][i] = 1;
    par[1][0] = 1; depth[1] = 0;
    dfs(1);

    for(int j = 1; j < logn; ++j) {
        for(int i = 1; i <= n; ++i) {
            int u = par[i][j - 1];
            par[i][j] = par[u][j - 1];
            for(int x = 0; x < 4; ++x) {
                int dn = x&2, up = x&1;
                dp[i][j][x] = max(dp[i][j - 1][dn + 1] + dp[u][j - 1][up + 2] - v[u], dp[i][j - 1][dn] + dp[u][j - 1][up]);
            }
        }
    }
}

int solve(int a, int b) {
    int c = a, d = b;
    if(a == b) return v[a];

    if(depth[a] > depth[b]) {
        swap(a, b);
        swap(c, d);
    }
    int l[4] = {}, r[4] = {};
    bool fl = 0, fr = 0;

    int diff = depth[b] - depth[a];
    for(int j = logn - 1; j >= 0; --j) {
        if(diff & (1LL << j)) {
            if(!fr) {
                fr = 1;
                for(int i = 0; i < 4; ++i) r[i] = dp[b][j][i];
            }
            else {
                int tmp[4];
                for(int x = 0; x < 4; ++x) {
                    int dn = x&2, up = x&1;
                    tmp[x] = max(r[dn + 1] + dp[b][j][up + 2] - v[b], r[dn] + dp[b][j][up]);
                }
                for(int i = 0; i < 4; ++i) r[i] = tmp[i];
            }
            b = par[b][j];
        }
    }

    if(a == b) {
        return max({r[1], r[2], r[3], r[0]});
    }

    bool flag = 0;
    for(int j = logn - 1; j >= -1; --j) {
        if(j != -1 && par[a][j] == par[b][j]) continue;
        if(j == -1) flag = 1, j++;
        if(!fl) {
            fl = 1;
            for(int i = 0; i < 4; ++i) l[i] = dp[a][j][i];
        }
        else {
            int tmp[4];
            for(int x = 0; x < 4; ++x) {
                int dn = x&2, up = x&1;
                tmp[x] = max(l[dn + 1] + dp[a][j][up + 2] - v[a], l[dn] + dp[a][j][up]);
            }
            for(int i = 0; i < 4; ++i) l[i] = tmp[i];
        }
        a = par[a][j];

        if(!fr) {
            fr = 1;
            for(int i = 0; i < 4; ++i) r[i] = dp[b][j][i];
        }
        else {
            int tmp[4];
            for(int x = 0; x < 4; ++x) {
                int dn = x&2, up = x&1;
                tmp[x] = max(r[dn + 1] + dp[b][j][up + 2] - v[b], r[dn] + dp[b][j][up]);
            }
            for(int i = 0; i < 4; ++i) r[i] = tmp[i];
        }
        b = par[b][j];
        if(flag) break;
    }

    return max(max(l[1], l[3]) + max(r[1], r[3]) - v[a], max(l[0], l[2]) + max(r[0], r[2]));
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(int i = 1; i <= n; ++i) cin >> v[i];
    for(int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        adj[u].eb(v); adj[v].eb(u);
    }

    precompute();
    for(int tt = 1; tt <= q; ++tt) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << nl;
    }
}
