#include "bits/stdc++.h"
using namespace std;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    const int inf = 1'000'000'001;
    int n;
    cin >> n;
    int x[n + 1];
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
 
    int ans = 0;
    int a[n + 1];
    a[0] = -inf;
    for(int i = 1; i <= n; ++i) a[i] = inf;
 
    for(int i = 1; i <= n; ++i) {
        int j = lower_bound(a, a + n + 1, x[i]) - a;
        if(a[j - 1] < x[i] && x[i] <= a[j]) {
            a[j] = x[i];
            if(j > ans) ans = j;
        }
    }
    cout << ans;
}
