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
 
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        h.insert(x);
    }
 
    while(m--) {
        int t;
        cin >> t;
        auto ptr = h.upper_bound(t);
        if(ptr == h.begin()) {
            cout << -1 << nl;
            continue;
        }
        --ptr;
        cout << *ptr << nl;
        h.erase(h.find(*ptr));
    }
}
