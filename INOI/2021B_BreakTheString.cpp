#include "bits/stdc++.h"
using namespace std;

#define int long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"
#define mp make_pair

struct SegTree{
    int n; vector<pair<int, int>> tree;
    SegTree() {}
    SegTree(int N) {
        n = 1;
        while(n < N) n *= 2;
        tree.resize(2*n, mp(n, n));
    }

    void mod(int x, pair<int, int> v) {
        x += n;
        if(tree[x] <= v) return;
        tree[x] = v;
        for(x /= 2; x >= 1; x /= 2) tree[x] = min(tree[2*x], tree[2*x + 1]);
    }

    pair<int, int> qry(int l, int r) {
        if(l < 0) l = 0; if(r >= n) r = n - 1;
        l += n; r += n;
        pair<int, int> res = mp(n, n);
        while(l <= r) {
            if(l % 2 == 1) res = min(res, tree[l++]);
            if(r % 2 == 0) res = min(res, tree[r--]);
            l /= 2; r /= 2;
        }
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int tot = 0;
    for(char c : s) {
        tot += (c == '1' ? 1 : -1);
    }
    if(tot < 0) {
        for(char &c : s) {
            c = '1' + '0' - c;
        }
        tot = -tot;
    }
    int cnt = (s[0] == '1' ? 1 : -1);
    cout << '1';
    for(int i = 1; i < n; ++i) {
        char c = s[i];
        cnt += (c == '1' ? 1 : -1);
        if(tot > k && cnt > k) {
            cnt -= k;
            tot -= k;
            cout << '1';
        }
        else {
            cout << '0';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        /* cout << "Case #" << i << nl; */
        solve();
        cout << nl;
    }
}

