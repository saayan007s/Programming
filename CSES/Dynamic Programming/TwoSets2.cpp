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
 
ll sum(ll a, ll b)
{
    return ((a+b)%mod + mod)%mod;
}
 
signed main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	ll n;
    cin >> n;
    ll target = n*(n+1)/2;
    if(target%2 != 0) {
        cout << 0 << nl;
        return 0;
    }
    target /= 2;
 
    ll dp[n+1][target+1] = {};
    dp[0][0] = 1;
    dp[1][0] = dp[1][1] = 1;
 
    f(i,2,n)
    {
        dp[i][0] = 1;
        f(j,1,target + 1)
        {
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0)
                dp[i][j] = sum(dp[i][j], dp[i-1][j-i]);
            // cout << dp[i][j] << " ";
        }
        // cout << nl;
    }
 
    cout << (dp[n-1][target]%mod);
}
