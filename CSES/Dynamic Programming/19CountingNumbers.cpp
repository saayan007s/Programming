#include "bits/stdc++.h"
using namespace std;
 
using ll = long long;
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define repd(i, a, b) for(int i = (a); i >= (b); --i)
 
#define em emplace
#define eb emplace_back
 
#define pi pair<int, int>
#define fr first
#define sc second
#define mp make_pair
 
ll solve(ll n) {
    if(n < 0) return 0;
    if(n == 0) return 1;
    ll res = 0;
    vector<int> digs;
    ll tmp = n;
    while(tmp) {
        digs.eb(tmp % 10);
        tmp /= 10;
    }
    reverse(digs.begin(), digs.end());
    int sz = digs.size();
 
    ll dp[sz][10][2] = {};
 
    for(int j = 1; j <= digs[0]; ++j) dp[0][j][j < digs[0]] = 1;
    for(int i = 1; i < sz; ++i) {
        for(int j = 0; j < 10; ++j) {
            if(j != 0) ++dp[i][j][1];
            for(int pr = 0; pr < 10; ++pr) {
                if(j == pr) continue;
                dp[i][j][1] += dp[i-1][pr][1];
                if(j < digs[i]) dp[i][j][1] += dp[i-1][pr][0];
            }
        }
        if(digs[i] != digs[i - 1]) dp[i][digs[i]][0] += dp[i-1][digs[i-1]][0];
    }
    res = 0;
    for(int j = 0; j < 10; ++j) res += dp[sz - 1][j][0] + dp[sz - 1][j][1];
    return ++res;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll a, b; cin >> a >> b;
    ll res = solve(b) - solve(a - 1);
    cout << res;
}
