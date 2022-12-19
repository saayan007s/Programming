#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define f(i,a,b) for(ll i = a; i <= b; i++)
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
 
	ll n;
    cin >> n;
    ll x[n+1];
    ll dp[n+1][n+1] = {};
    ll s[n+1] = {}; //prefix sum
 
    f(i,1,n)
    {
        cin >> x[i];
 
        dp[i][i] = x[i];
        s[i] = s[i-1] + x[i];
    }
 
    f(w,1,n-1)
    {
        f(i,1,n-w)
        {
            ll j = i + w;
 
            dp[i][j] = max(x[i] - dp[i+1][j], x[j] - dp[i][j-1]);
        }
    }
 
    ll ans = (dp[1][n] + s[n])/2;
    cout << ans;
}
