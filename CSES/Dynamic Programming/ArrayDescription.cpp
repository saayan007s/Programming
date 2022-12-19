#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define f(i,a,b) for(ll i = a; i < b; i++)
#define fd(i,a,b) for (ll i = a; i>=b; i--)
 
#define fr first 
#define sc second 
#define pb push_back
 
#define pii pair<ll,ll>
#define vi vector<ll>
 
#define nl '\n'
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
const ll mod = 1e9 + 7;
ll n,m;
ll x[100001];
ll dp[100001][101] = {};
ll ans = 0;
// dp[i][j] = number of ways x[i] = j
 
ll sum(ll a, ll b)
{
    return ((a+b)%mod + mod)%mod;
}
signed main() 
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	cin >> n >> m;
    f(i,1,n+1)
        cin >> x[i];
 
    if(x[1])
        dp[1][x[1]] = 1;
    else
        f(j,1,m+1)
            dp[1][j] = 1;
 
    f(i,2,n+1)
    {
        if(x[i])
        {
            dp[i][x[i]] = sum(dp[i][x[i]], dp[i-1][x[i]]);
            if(x[i] - 1)
                dp[i][x[i]] = sum(dp[i][x[i]], dp[i-1][x[i] - 1]);
            if(x[i] + 1 <= m)
                dp[i][x[i]] = sum(dp[i][x[i]], dp[i-1][x[i] + 1]);
        }
        else
        {
            f(j,1,m+1)
            {
                dp[i][j] = sum(dp[i][j], dp[i-1][j]);
                if(j-1)
                    dp[i][j] = sum(dp[i][j], dp[i-1][j - 1]);
                if(j+1 <= m)
                    dp[i][j] = sum(dp[i][j], dp[i-1][j + 1]);
            }
        }
    }
 
    f(j,1,m+1)
        ans = sum(ans, dp[n][j]);
    cout << ans;
}
