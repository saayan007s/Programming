#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

struct UFDS {
    int n;
    vector<int> lnk, sz, mus;

    UFDS(int N) {
        n = N;
        lnk.resize(n);
        for(int i = 0; i < n; ++i) lnk[i] = i;
        sz.resize(n, 1);
        mus.resize(n, 0);
    }

    int find(int a) {
        return (a == lnk[a] ? a : lnk[a] = find(lnk[a]));
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        
        if(sz[a] < sz[b]) swap(a, b);
        lnk[b] = a;
        sz[a] += sz[b];
        mus[a] += mus[b];
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    pair<int, int> roads[m];
    for(auto &[u, v] : roads) cin >> u >> v;

    UFDS uf(n + 1);
    for(int i = 1; i <= n; ++i) {
        int x; cin >> x;
        uf.mus[i] = x;
    }

    for(auto [u, v] : roads)
        uf.unite(u, v);

    int grps = 0;
    vector<int> num;
    for(int i = 1; i <= n; ++i) {
        if(uf.find(i) == i) {
            ++grps;
            num.eb(uf.mus[i]);
        }
    }

    if(grps < k) {
        cout << -1 << nl; return;
    }
    int lav = grps - 1, nikh = 0;
    sort(num.begin(), num.end());

    int res = 0;
    for(int i = 0; i < k; ++i) {
        if(i & 1) res += num[nikh++];
        else res += num[lav--];
    }
    cout << res << nl; return;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i)
        solve();
}
