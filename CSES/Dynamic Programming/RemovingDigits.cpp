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
    // freopen("input.txt","r","stdin");
    // freopen("output.txt","w","stdout");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    ll n;
    cin >> n;
    ll dp[n+1];
    dp[0] = 0;
 
    f(i,1,n+1)
    {
        ll tmp = i;
        dp[i] = INT_MAX;
        while(tmp != 0)
        {
            ll digit = tmp%10;
            if(i - digit >= 0)
                dp[i] = min(dp[i - digit] + 1, dp[i]);
            tmp /= 10;
        }
    }
 
    cout << dp[n];
}
