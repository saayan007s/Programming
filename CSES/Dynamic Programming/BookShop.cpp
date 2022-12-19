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
 
signed main() 
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
	ll n,x;
	cin >> n >> x;
	pii a[n];
	f(i,0,n)
		cin >> a[i].fr;
	f(i,0,n)
		cin >> a[i].sc;
 
	ll dp[x+1] = {};
	f(i,0,n)
	{
		fd(j,x,1)
		{
			if(j >= a[i].fr)
			dp[j] = max(dp[j], dp[j - a[i].fr] + a[i].sc);
		}
	}
 
	cout << dp[x];
}
