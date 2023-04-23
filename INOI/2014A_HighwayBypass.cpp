#include "bits/stdc++.h"
using namespace std;

#define long long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, d;
    cin >> r >> c >> d;
    bool b[r + 1][c + 1] = {};
    for(int i = 1; i <= r; ++i)
        for(int j = 1; j <= c; ++j)
            cin >> b[i][j];

    const int mod = 20011;
    pair<int, int> dp[r + 1][c + 1] = {};
    dp[1][1] = {1, 1};
    for(int i = 1; i <= r; ++i) {
        for(int j = 1; j <= c; ++j) {
            if(!b[i][j]) continue;
            for(int k = i - 1; k >= i - d && k > 0; --k)
                if(!b[k][j]) break;
                else dp[i][j].fr = (dp[i][j].fr + dp[k][j].sc) % mod;

            for(int k = j - 1; k >= j - d && k > 0; --k)
                if(!b[i][k]) break;
                else dp[i][j].sc = (dp[i][j].sc + dp[i][k].fr) % mod;
        }
    }

    cout << (dp[r][c].fr + dp[r][c].sc) % mod;
}
