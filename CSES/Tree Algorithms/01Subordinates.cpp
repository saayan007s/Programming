#include "bits/stdc++.h"
using namespace std;
 
#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int n; cin >> n;
    vector<int> ch[n + 1];
    int par[n + 1];
    for(int i = 2; i <= n; ++i) {
        cin >> par[i];
        ch[par[i]].eb(i);
    }
    int cnt[n + 1];
    /* auto dfs = [&] (auto& self, int v) -> void { */
    function<void(int)> dfs = [&](int v) {
        cnt[v] = 0;
        for(int u : ch[v]) {
            dfs(u);
            cnt[v] += 1 + cnt[u];
        }
    };
    dfs(1);
    for(int i = 1; i <= n; ++i) cout << cnt[i] << ' ';
}
