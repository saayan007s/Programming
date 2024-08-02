#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();
    int dp[n + 1][m + 1] = {};
    pair<int, int> par[n + 1][m + 1];

    int len = 0;
    pair<int, pair<int, int>> opt1, opt2, opt3, opt;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            opt1 = make_pair(dp[i - 1][j], make_pair(i - 1, j));
            opt2 = make_pair(dp[i][j - 1], make_pair(i, j - 1));
            if(s[i - 1] == t[j - 1]) opt3 = make_pair(dp[i - 1][j - 1] + 1, make_pair(i - 1, j - 1));
            else opt3 = make_pair(-1, make_pair(0, 0));

            opt = max({opt1, opt2, opt3});

            dp[i][j] = opt.first, par[i][j] = opt.second;
        }
    }

    string res = "";
    pair<int, int> cur = make_pair(n, m);
    pair<int, int> prv = par[n][m];

    while(cur != make_pair(0, 0)) {
        if(cur.first - prv.first == cur.second - prv.second) {
            res.push_back(s[cur.first - 1]);
        }
        cur = prv;
        prv = par[cur.first][cur.second];
    }
    reverse(res.begin(), res.end());
    cout << res;
}
