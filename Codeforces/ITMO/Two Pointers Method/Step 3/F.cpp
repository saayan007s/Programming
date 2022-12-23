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
    ll n, m;
    cin >> n >> m;
    string s, c;
    cin >> s >> c;
    vl a(n), b(26);
    fur(i, 0, n - 1)
        a[i] = s[i] - 'a';
    fur(i, 0, m - 1)
        ++b[c[i] - 'a'];

    ll ans = 0;
    vl cnt(26);
    ll l = 0;
    fur(r, 0, n - 1) {
        ++cnt[a[r]];
        while(cnt[a[r]] > b[a[r]] && l <= r) {
            --cnt[a[l]];
            ++l;
        }
        if(l <= r) {
            ans += r - l + 1;
            /* cout << r + 1 << ' ' << r - l + 1 << nl; */
        }
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

