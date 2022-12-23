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
#define each(u, v) for(auto &u : v )
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

void solve()
{
    /* taking input */
    ll n, c;
    cin >> n >> c;
    string s;
    cin >> s;

    /* solving the problem */
    ll a = 0;
    ll b = 0;
    ll ans = 0;
    ll rd = 0;
    ll l = 0;

    fur(r, 0, n - 1) {
        if(s[r] == 'a')
            ++a;
        else if(s[r] == 'b') {
            ++b;
            rd += a;
        }

        while(rd > c) {
            if(s[l] == 'a') {
                --a;
                rd -= b;
            } else if(s[l] == 'b') {
                --b;
            }
            ++l;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << nl;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	ll t = 1;
    /* cin >> t; */
    while(t--)
    {
        solve();
    }
}

