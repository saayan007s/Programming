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
 
ll n, maxdp = 1;
ll x[100];
bool dp[100001] = {};
ll ans = 0;
 
signed main() 
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
	    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	cin >> n;
	f(i,0,n) 
	{
		cin >> x[i];
		maxdp += x[i];
	}
 
	dp[0] = 1;
 
	f(i,0,n)
	{
		// cout << "using " 	<< x[i] << "\n\t";
		fd(j,maxdp-1,0)
		{
			if(dp[j] && j + x[i] < maxdp)
				if(!dp[j + x[i]])
				{
					dp[j + x[i]] = 1;
					ans++;
				}
			// cout << dp[j] << " ";
		}
		// cout << nl;
	}
 
	cout << ans << nl;
	f(i,1,maxdp) 
		if(dp[i])
			cout << i << " ";
 
}
