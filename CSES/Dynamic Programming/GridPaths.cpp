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
typedef long long ll;
 
int main() 
{
    int n;
    cin >> n;
    bool grid[n][n];
    f(i,0,n){
        f(j,0,n){
            char c;
            cin >> c;
            grid[i][j] = (c == '.' ? 1 : 0);
        }
    }
 
    ll dp[n][n] = {};
    dp[0][0] = grid[0][0];
    const ll mod = 1e9 + 7;
    f(i,0,n)
    {
        f(j,0,n)
        {
            if(i-1 >= 0)
                if(grid[i][j]){
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
 
            if(j-1 >= 0)
                if(grid[i][j]){
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
 
            // cout << dp[i][j] << " ";
        }
    }
 
    cout << dp[n-1][n-1];
}
