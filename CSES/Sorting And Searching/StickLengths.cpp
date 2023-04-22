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
    int p[n]; for(int &i : p) cin >> i;
    sort(p, p + n);
    int res = 0, v = p[n / 2];
    for(int i : p) res += abs(v - i);
    cout << res << nl;
}
