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
#define pii pair<int,int>
#define pll pair<ll,ll>
#define nl '\n'
#define vi vector<int>
#define vl vector<ll>
 
const ll maxN = 502;
 
signed main() 
{   
        // freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll a,b;
    cin >> a >> b;
    ll dp[maxN][maxN] = {};
 
    dp[1][1] = 0;
 
    f(i,1,maxN)
    {
        dp[i][i] = 0;
        f(j,1,i+1)
            dp[i][j] = dp[j][i];
        f(j,i+1,maxN)
        {
            dp[i][j] = dp[ min(i,j-i) ][ max(i,j-i) ] + 1;
 
            f(k,1,i)
            {
                dp[i][j] = min(dp[i][j], dp[ min(i,k) ][ max(i,k) ] + dp[ min(i,j-k) ][ max(i,j-k) ] + 1);
                dp[i][j] = min(dp[i][j], dp[ min(k,j) ][ max(k,j) ] + dp[ min(i-k,j) ][ max(i-k,j) ] + 1);
            }
 
        }
    }
    cout << dp[a][b] << nl;
}
