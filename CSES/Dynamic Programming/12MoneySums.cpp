#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    const int A = 100'000;
    bitset<A + 1> dp;

    dp[0] = 1;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        dp |= dp << x;
    }

    dp[0] = 0;
    cout << dp.count() << '\n';
    for(int i = 1; i <= A; ++i) if(dp[i]) cout << i << ' ';
}
