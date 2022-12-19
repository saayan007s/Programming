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
	ll n,x;
    cin >> n >> x;
    ll c[n];
    ll dp[x+1];
    f(i,0,n)
    {
        cin >> c[i];
    }
    f(i,0,x+1)  dp[i] = INT_MAX;
 
    dp[0] = 0;
    f(i,1,x+1) {
        f(j,0,n) {
            if(i - c[j] >= 0)
                // if(dp[i - c[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - c[j]] + 1);
        }
    }
    if(dp[x] != INT_MAX)
        cout << dp[x];
    else cout << "-1";
}
