#include <bits/stdc++.h>
using namespace std;
 
typedef int64_t ll;
 
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
typedef vector<int> vi;
typedef vector<ll> vl;
 
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
 
#define fr first 
#define sc second
#define pb push_back
#define mp make_pair
 
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<vl> dp(n + 1, vl(n + 1));
    fur(i, 1, n) {
        fur(j, 1, n) {
            char c;
            cin >> c;
            // cout << c;
            dp[i][j] = (c == '*') + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        }
        // cout << nl;
    }
 
    while(q--) {
        ll x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        
        cout << dp[xx][yy] - dp[xx][y - 1] - dp[x - 1][yy] + dp[x - 1][y - 1] << nl;
    }
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
	ll t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }
}
