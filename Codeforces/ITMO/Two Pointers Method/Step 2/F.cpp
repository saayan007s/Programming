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
    deque<pl> mn;
    deque<pl> mx;
    ll l = 0;
    ll res = 0;

    ll lo = 1e18 + 1;
    ll hi = -1;
    fur(r, 0, n - 1) {
        while(!mn.empty() && mn.front().fr > a[r])
            mn.pop_front();
        mn.push_front({a[r], r});
        while(!mx.empty() && mx.front().fr < a[r])
            mx.pop_front();
        mx.push_front({a[r], r});

        lo = mn.back().fr;
        hi = mx.back().fr;
        while(hi - lo > k) {
            if(mn.back().sc == l)
                mn.pop_back();
            if(mx.back().sc == l)
                mx.pop_back();
            lo = mn.back().fr;
            hi = mx.back().fr;
            ++l;
        }
        res += r - l + 1;
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

