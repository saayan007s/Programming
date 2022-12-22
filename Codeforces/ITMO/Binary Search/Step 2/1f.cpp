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

bool check(ll mid, vl a, string t, string p) {
    ll n = t.length();
    ll m = p.length();
    vector<bool> used(n);
    fur(i, 0, mid - 1)
        used[a[i]] = 1;

    ll j = 0;
    fur(i, 0, n - 1) {
        if(!used[i]) {
            if(j < m && t[i] == p[j])
                ++j;
        }
    }
    return j == m;
}

void solve()
{
    /* taking input */
    string t, p;
    cin >> t >> p;
    ll n = t.length();
    vl a(n);
    for(auto &u : a) {
        cin >> u;
        --u;
    }

    /* solving the problem */
    ll lo = 0;
    ll hi = n;
    while(lo + 1 != hi) {
        ll m = (lo + hi) / 2;
        (check(m, a, t, p) ? lo : hi) = m;
    }
    cout << lo << nl;
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

