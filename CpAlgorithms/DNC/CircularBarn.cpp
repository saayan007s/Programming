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

    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);

    int n;
    cin >> n;
    int r[n];
    for(int &i : r) cin >> i;

    int res = 1e18L;
    for(int i = 0; i < n; ++i) {
        int opt = 0;
        for(int j = i; j < i + n; ++j) {
            opt += r[j % n] * (j - i);
        }
        res = min(res, opt);
    }

    cout << res << nl;
}
