#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 2e5L + 1;
int n;
vector<int> adj[N];
int cnt[N], mx[N];

void dfs(int x, int p) {
    cnt[x] = 1;
    mx[x] = 0;
    for(int y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        cnt[x] += cnt[y];
        mx[x] = max(mx[x], cnt[y]);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i < n; ++i) {
        int a, b; cin >> a >> b;
        adj[a].eb(b); adj[b].eb(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; ++i) {
        if(i != 1) mx[i] = max(mx[i], cnt[1] - cnt[i]);
        if(mx[i] <= n/2) {
            cout << i << nl;
            return 0;
        }
    }
}
