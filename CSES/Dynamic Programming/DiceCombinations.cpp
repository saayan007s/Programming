#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fd(i,a,b) for (int i = a; i>=b; i--)
#define F first 
#define S second 
#define PB push_back
#define pii pair<int,int>
#define pll pair<long,long>
#define nl '\n'
#define vi vector<int>
#define mod 1000000007
typedef long long ll;
 
int main() 
{
    ll n; cin >> n;
    ll dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    f(i,2,n+1)
    {
        dp[i] = 0;
        f(j,1,7)
            if(i-j < 0)
                continue;
            else
                dp[i] += dp[i-j]%mod;
    }
    cout << dp[n]%mod;
}
