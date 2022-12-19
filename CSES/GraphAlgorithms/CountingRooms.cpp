#include <bits/stdc++.h>
#include <iostream>
using namespace std;
 
#define f(i,a,b) for(int i = a; i < b; i++)
#define fd(i,a,b) for (int i = a; i>=b; i--)
#define fr first 
#define sc second 
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define nl '\n'
#define vi vector<int>
 
typedef long long ll;
 
int n,m;
int ans;
bool vis[1000][1000];
int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};
 
void dfs(int x, int y){
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int dx = x+h[i], dy = y+v[i];
        if(0 <= dx && dx < n && 0 <= dy && dy < m && !vis[dx][dy])
            dfs(dx, dy);
    }
}
 
int main() 
{
    // freopen("input.txt","r","stdin");
    // freopen("output.txt","w","stdout");
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    cin >> n >> m;
    ans = 0;
    f(i,0,n)
        f(j,0,m)
        {
            char c; cin >> c;
            vis[i][j] = (c == '#');
        }
 
    f(i,0,n)
    {
        f(j,0,m) 
        {
            if(!vis[i][j])
            {
                dfs(i,j);
                ans++;
            }
        }
    }
 
    cout << ans << nl;
}
