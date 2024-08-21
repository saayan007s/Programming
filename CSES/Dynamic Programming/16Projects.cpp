#include "bits/stdc++.h"
using namespace std;

using ll = long long;

#define eb emplace_back
#define fr first
#define sc second
#define mp make_pair

const char nl = '\n';
bool dbg = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef local
    dbg = 1;
#endif

    int n;
    cin >> n;
    vector<vector<int>> x(n, vector<int>(3));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) {
            cin >> x[i][j];
        }
    }

    sort(x.begin(), x.end(), [&](const vector<int>& i, const vector<int>& j) {
        return i[1] < j[1];
    });

    auto find = [&](int t) -> int {
        if(x[0][1] >= t) return -1;
        int lo = 0, hi = n, mid;
        while(lo + 1 < hi) {
            mid = (lo + hi) / 2;
            (x[mid][1] < t ? lo : hi) = mid;
        }
        return lo;
    };

    vector<int64_t> dp(n);
    dp[0] = x[0][2];
    for(int i = 1; i < n; ++i) {
        int j = find(x[i][0]);
        dp[i] = max(dp[i - 1], x[i][2] + (j == -1 ? 0 : dp[j]));
    }
    cout << dp.back();
    return 0;
}
