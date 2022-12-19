#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
#define f(i,a,b) for(ll i = a; i < b; i++)
#define fd(i,a,b) for (int i = a; i>=b; i--)
#define F first 
#define S second 
#define PB push_back
#define pii pair<int,int>
#define pll pair<long,long>
#define nl '\n'
#define vi vector<int>
typedef long long ll;
 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll mod = 1e9 + 7;
	ll n,x;
    cin >> n >> x;
 
    ll c[n];
    ll dp[x+1] = {};
 
    f(i,0,n)
    {
        cin >> c[i];
    }
 
    dp[0] = 1;
 
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= x; j++) {
            if(j - c[i] >= 0) 
                dp[j] = (dp[j] + dp[j - c[i]]) % mod;
 
        }
    }
 
 
    cout << (dp[x]%mod);
}
