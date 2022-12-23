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

vl tree;
ll n;

void update(ll pos, ll val) {
    pos += n;
    tree[pos] = val;
    while(pos >= 2) {
        pos /= 2;
        tree[pos] = min(tree[2 * pos], tree[2*pos + 1]);
    }
}

ll query(ll qlo, ll qhi) {
    ll ans = 1e10;
    ll l = qlo + n;
    ll r = qhi + n;
    while(l <= r) {
        if(r%2 == 0)
            ans = min(ans, tree[r--]);
        if(l%2 == 1)
            ans = min(ans, tree[l++]);
        r /= 2;
        l /= 2;
    }
    return ans;
}


void print() {
    fur(i, 1, 2*n - 1) {
        cout << tree[i] << ' ';
        if(! (i & (i + 1))) 
            cout << nl;
    }
    cout << nl << nl;
}

void solve()
{
    ll N, q;
    cin >> N >> q;
    n = N;
    while(__builtin_popcountll(n) != 1)
        ++n;
    tree.resize(2 * n, 1e10);
    fur(i, 0, N - 1) {
        ll tmp;
        cin >> tmp;
        update(i, tmp);
    }

    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll p, v;
            cin >> p >> v;
            update(p, v);
        } else {
            ll a, b;
            cin >> a >> b;
            --b;
            cout << query(a, b) << nl;
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

