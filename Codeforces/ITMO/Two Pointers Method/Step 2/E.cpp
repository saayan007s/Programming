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
    ll n, k;
    cin >> n >> k;
    vl a(n);
    for(auto &u : a)
        cin >> u;

    /* solving the problem */
    map<ll, ll> m;
    ll res = 0;
    ll cnt = 0;
    ll l = 0;
    fur(r, 0, n - 1) {
        if(m[a[r]] == 0)
            ++cnt;
        ++m[a[r]];
        while(cnt > k) {
            if(m[a[l]] == 1)
                --cnt;
            --m[a[l]];
            ++l;
        }
        res += r - l + 1;
        /* cout << r - l + 1 << nl; */
    }
    cout << res << nl;
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

