#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
#define f(i,a,b) for(ll i = a; i < b; i++)
#define fd(i,a,b) for (ll i = a; i >= b; i--)
 
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
 
	string s,t;
    cin >> s >> t;
    ll sl = s.length(), tl = t.length();
 
    ll dp[sl+1][tl+1] = {};
    s = " " + s;
    t = " " + t;
 
    // base
    dp[1][1] = (s[1] != t[1]);
 
    f(j,2,tl+1)
    {
        if(s[1] == t[j])
            dp[1][j] = j-1;
        else
            dp[1][j] = dp[1][j-1] + 1;
    }
    f(i,2,sl+1)
    {
        if(s[i] == t[1])
            dp[i][1] = i-1;
        else
            dp[i][1] = dp[i-1][1] + 1;
        // dp[i][1] = dp[i-1][1] + (ll)(t[1] != s[i]);
    }
 
    // inductive
    f(i,2,sl+1)
    {
        f(j,2,tl+1)
        {
            if(s[i] == t[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min( dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]) ) + 1;
        }
    }
    cout << dp[sl][tl] << nl;
}
