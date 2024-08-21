#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
	string s,t;
    cin >> s >> t;
    int sl = s.size(), tl = t.size();
 
    vector<vector<int>> dp(sl + 1, vector<int>(tl + 1, sl + tl));
 
    dp[0][0] = 0;
    for(int i = 1; i <= sl; ++i) dp[i][0] = i;
    for(int j = 1; j <= tl; ++j) dp[0][j] = j;

    for(int i = 1; i <= sl; ++i) {
        for(int j = 1; j <= tl; ++j) {
            dp[i][j] = min({dp[i - 1][j] + 1,
                            dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + (s[i - 1] != t[j - 1] ? 1 : 0)
                        });
        }
    }
    cout << dp[sl][tl];
}
