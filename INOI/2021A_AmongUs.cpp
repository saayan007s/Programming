#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

struct UFDS {
    int n;
    vector<int> lnk, sz, ene;
    bool pos;

    UFDS(int N) {
        n = N - 1;
        lnk.resize(N); iota(lnk.begin(), lnk.end(), 0);
        sz.resize(N, 1);
        ene.resize(N, 0);
        pos = 1;
    }

    int find(int a) {
        if(!pos) return 0;
        return (a == lnk[a] ? a : lnk[a] = find(lnk[a]));
    }

    int unite(int a, int b) {
        if(a == 0 || b == 0 || !pos) return max(a, b);
        a = find(a); b = find(b);
        if(a == b) return a;
        if(sz[a] < sz[b]) swap(a, b);
        lnk[b] = a;
        sz[a] += sz[b];
        return a;
    }

    void frnd(int a, int b) {
        a = find(a); b = find(b);
        if(ene[a] == b || !pos) {
            pos = 0;
            return;
        }
        int c = ene[a], d = ene[b];
        a = unite(a, b);
        c = unite(c, d);
        ene[a] = c;
        ene[c] = a;
    }

    void neme(int a, int b) {
        a = find(a); b = find(b);
        if(a == b || !pos) {
            pos = 0;
            return;
        }
        int c = ene[a], d = ene[b];
        a = unite(a, d);
        b = unite(b, c);
        ene[a] = b;
        ene[b] = a;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    UFDS uf(n + 1);

    for(int tt = 1; tt <= q; ++tt) {
        int type, i, j;
        cin >> type >> i >> j;
        if(type == 2) uf.frnd(i, j);
        else uf.neme(i, j);
    }

    if(!uf.pos) {
        cout << -1 << nl;
    }
    else {
        int res = 0;
        for(int i = 1; i <= n; ++i) {
            if(uf.find(i) == i && uf.ene[i] < i) {
                res += max(uf.sz[i], uf.sz[uf.ene[i]]);
            }
        }
        cout << res << nl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        solve();
    }
}

