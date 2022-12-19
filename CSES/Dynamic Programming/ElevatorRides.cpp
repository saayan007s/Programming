#include <bits/stdc++.h>
using namespace std;
 
/* higher types */
typedef int64_t ll;
typedef long double ld;
 
/* pairs */
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
 
/* vectors */
typedef vector<int> vi;
typedef vector<ll> vl;
 
typedef vector<pi> vpi;
typedef vector<pl> vpl;
 
/* loops */
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
 
/* shortforms */
#define fr first 
#define sc second
#define pb push_back
#define mp make_pair
 
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
/* constants */
const ll infl = numeric_limits<int64_t>::max();
const int infi = numeric_limits<int>::max();
const int modi = 1e9 + 7;
const ll modl = 1e9 + 7;
 
void solve()
{
    ll n, x;
    cin >> n >> x;
    ll w[n];
    fur(i, 0, n-1)
        cin >> w[i];
 
    pl dp[1 << n];// fr is number of rides, sc is weight in the last ride
    dp[0] = mp(1, 0);
    
    fur(i, 1, (1<<n) - 1)// pull dp
    {
        dp[i] = mp(n+1, 0);
        fur(j, 0, n-1)
        {
            if(!(i&(1<<j)))// if j-th person is not riding
                continue;
 
            auto option = dp[i - (1<<j)];
            if(option.sc + w[j] > x) // add a new ride
            {
                option.fr++;
                option.sc = w[j];
            }
            else{// add to this ride;
                option.sc += w[j]; 
            }
 
            dp[i] = min(dp[i], option);
        }
    }
    // fur(i, 0, (1<<n) - 1)
        // cout << i << ' ' << dp[i].fr << ' ' << dp[i].sc << nl;
 
    cout << dp[(1<<n) - 1].fr << nl;
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
 
