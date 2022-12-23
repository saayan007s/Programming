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

ll n;
vl tree;

void update(ll pos, ll val) {
    pos += n;
    tree[pos] = val;
    pos /= 2;
    while(pos >= 1) {
        tree[pos] = tree[pos * 2] + tree[pos*2 + 1];
        pos /= 2;
    }
}

ll query(ll node, ll lo, ll hi, ll k) {
    if(lo == hi)
        return lo;

    ll mid = (lo + hi) / 2;
    if(tree[2*node] >= k)
        return query(2*node, lo, mid, k);
    else
        return query(2*node + 1, mid + 1, hi, k - tree[2*node]);
}

void solve()
{
    ll N, q;
    cin >> N >> q;
    n = N;
    while(__builtin_popcountll(n) != 1)
        ++n;
    tree.resize(2 * n);

    fur(i, 0, N - 1) {
        ll tmp;
        cin >> tmp;
        update(i, tmp);
    }

    while(q--) {
        ll type;
        cin >> type;
        if(type == 1) {
            ll i;
            cin >> i;
            update(i, 1 - tree[n + i]);
        } else {
            ll k;
            cin >> k;
            cout << query(1, 0, n - 1, k + 1) << nl;
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

