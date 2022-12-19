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
 
ll n;
ll last[200001];
 
bool comp(tuple<ll,ll,ll> c1, tuple<ll,ll,ll> c2)
{
    ll a,b,p;
    ll c,d,q;
    tie(a,b,p) = c1;
    tie(c,d,q) = c2;
 
    if(b != d)
        return b < d;
    else
        return a < c;
}
 
ll bin_srch(ll a)
{
    ll lo = 1, hi = n, mid;
    while(lo != hi)
    {
        mid = (lo + hi)/2;
        if(last[mid] < a)
            lo = mid + 1;
        else if(last[mid] >= a)
            hi = mid;
    }
 
    return hi - 1;
}
 
signed main() 
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> n;
    tuple<ll,ll,ll> c[n + 1];
    c[0] = {-1,-1,-1};
    ll a,b,p;
 
    f(i,1,n+1)
    {
        cin >> a >> b >> p;
        c[i] = {a,b,p};
    }
 
    sort(c, c + n + 1, comp);
 
    f(i,1,n+1)
    {
        tie(a,b,p) = c[i];
        last[i] = b;
    }
 
    ll dp[n + 1] = {};
 
    // base case
    tie(a,b,p) = c[1];
    dp[1] = p;
 
    // inductive
    f(i,2,n+1)
    {
        tie(a,b,p) = c[i];
        dp[i] = max(dp[i-1], p + dp[bin_srch(a)]);
    }
    cout << dp[n];
}
