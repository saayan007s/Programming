#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    pair<int, int> a[n];
    for(int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = make_pair(x, y + z);
    }

    sort(a, a + n, [&](pair<int, int> left, pair<int, int> right) {
        return left.second > right.second;
    });

    int ans = 0, sum = 0;
    for(int i = 0; i < n; ++i) {
        sum += a[i].first;
        ans = max(ans, sum + a[i].second);
    }

    cout << ans << "\n";
}
