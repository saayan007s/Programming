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

ll N, n;
vl tree;

void update(ll pos, ll val) {
    pos += n;
    tree[pos] = val;
    pos /= 2;
    while(pos >= 1) {
        tree[pos] = max(tree[pos * 2], tree[pos * 2 + 1]);
        pos /= 2;
    }
}

ll query(ll node, ll lo, ll hi, ll x) {
    if(tree[1] < x)
        return N * N;
    if(lo == hi)
        return lo;

    ll mid = (lo + hi) / 2;
    ll a = 2 * node;
    ll b = a + 1;

    if(tree[a] >= x)
        return query(a, lo, mid, x);
    else
        return query(b, mid + 1, hi, x);
}

void solve()
{
    ll q;
    cin >> N >> q;
    n = N;
    while(__builtin_popcountll(n) != 1)
        ++n;

    tree = vl(2 * n, -1);
    fur(i, 0, N - 1)
        cin >> tree[n + i];
    ruf(i, n - 1, 1)
        tree[i] = max(tree[2*i], tree[2*i + 1]);

    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll i, v;
            cin >> i >> v;
            update(i, v);
        } else {
            ll x;
            cin >> x;
            ll ans = query(1, 0, n - 1, x);
            if(ans < N)
                cout << ans << nl;
            else
                cout << -1 << nl;
        }
    }
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

