#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fd(i,a,b) for (int i = a; i>=b; i--)
#define fr first 
#define sc second 
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define nl '\n'
#define vi vector<int>
#define vl vector<ll>
 
const ll mod = 1e9 + 7;
 
signed main() 
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll dp[1000001];
    ll s[1000001];
 
    dp[0] = s[0] = 1;
    dp[1] = 2;
    dp[2] = 8;
    s[1] = s[0] + dp[1];
    s[2] = s[1] + dp[2];
    f(i,3,1000001)
    {
        dp[i] = ( (5*dp[i-1] - 2*s[i-2])%mod + mod) %mod;
        s[i] = ((s[i-1] + dp[i])%mod + mod)%mod;
    }
 
    ll t = 0;
    scanf("%lld", &t);
    while(t--)
    {
        ll n;
        scanf("%lld", &n);
        printf("\n%lld", dp[n]);
    }
}
