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
 
    int n;
    cin >> n;
    pair<int, int> a[2*n];
    for(int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        a[2*i] = make_pair(l, 1);
        a[2*i + 1] = make_pair(r, -1); 
    }
    sort(a, a + 2*n);
 
    int res = 0;
    int cur = 0;
    int i = 0;
    while(i < 2*n) {
        int t = a[i].fr;
        while(i < 2*n && a[i].fr == t) {
            cur += a[i].sc;
            ++i;
        }
        res = max(res, cur);
    }
    cout << res << nl;
}
