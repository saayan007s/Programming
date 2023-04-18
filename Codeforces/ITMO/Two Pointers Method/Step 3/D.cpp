#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int res = 1e8L;
int n[4];
vector<int> a[4];
int ans[4];

inline int cost(int w, int x, int y, int z) {
    int opt = max({w, x, y, z}) - min({w, x, y, z});
    if(opt < res) {
        res = opt;
        ans[0] = w, ans[1] = x, ans[2] = y, ans[3] = z;
    }
    return opt;
}

void solve(int x) {
    int p[4] = {};
    for(int i = 0; i < n[x]; ++i) {
        p[x] = i;
        for(int j = 0; j < 4; ++j) {
            if(x == j) continue;
            while(p[j] + 1 < n[j] && a[j][p[j] + 1] <= a[x][p[x]]) {
                ++p[j];
            }
        }

        res = min(res, cost(a[0][p[0]], a[1][p[1]], a[2][p[2]], a[3][p[3]]));
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 4; ++i) {
        cin >> n[i];
        a[i].resize(n[i]);
        for(auto &u : a[i])
            cin >> u;
        sort(a[i].begin(), a[i].end());
        /* for(auto u : a[i]) cout << u << ' '; cout << nl; */
    }
    /* cout << nl; */

    for(int i = 0; i < 4; ++i) {
        /* if(i != 0) { */
        /*     swap(n[i], n[0]); */
        /*     swap(a[i], a[0]); */
        /* } */
        solve(i);
        /* if(i != 0) { */
        /*     swap(n[i], n[0]); */
        /*     swap(a[i], a[0]); */
        /* } */
    }

    for(auto u : ans) cout << u << ' '; cout << nl;
    /* cout << res << nl; */
}
