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
 
    int n, x; cin >> n >> x;
    int a[n];
    for(int &i : a) cin >> i;
 
    set<pair<int, int>> s;
    for(int i = 0; i < n; ++i) {
        auto ptr = s.lower_bound(make_pair(x - a[i], -1));
        if(ptr != s.end() && (*ptr).fr + a[i] == x){
            cout << (*ptr).sc + 1 << ' ' << i + 1 << nl;
            return 0;
        }
        s.insert(make_pair(a[i], i));
    }
 
    cout << "IMPOSSIBLE" << nl;
}
