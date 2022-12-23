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

struct SegTree {
    ll id = 0;
    ll n;
    vl tree;

    SegTree(int N) {
        build(N);
    }

    void build(int N) {
        n = N;
        while(__builtin_popcountll(n) != 1)
            ++n;
        tree = vl(2 * n);
    }

    ll query(ll node, ll lo, ll hi, ll ql, ll qh) {
        if(lo > qh || hi < ql)
            return 0;
        if(ql <= lo && hi <= qh)
            return tree[node];
        ll d = (lo + hi) / 2;

        return comb(query(2*node, lo, d, ql, qh), query(2*node + 1, d + 1, hi, ql, qh) );
    }

    ll query(ll ql, ll qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    ll comb(ll a, ll b) {
        if(b == 0)
            return a;
        return comb(b, a % b);
    }
};

void solve()
{
    /* taking input */
    ll n;
    cin >> n;
    vl a(n);
    for(auto &u : a)
        cin >> u;

    /* solving the problem */
    SegTree st(n);
    fur(i, 0, n - 1) {
        st.tree[st.n + i] = a[i];
    }
    ruf(i, st.n - 1, 1) {
        st.tree[i] = st.comb(st.tree[2*i], st.tree[2*i + 1]);
    }

    ll res = n + 1;
    ll l = -1;
    fur(r, 0, n - 1) {
        while(l != r && st.query(l + 1, r) == 1) {
            ++l;
        }
        if(st.query(l, r) == 1)
            res = min(res, r - l + 1);
    }
    cout << (res > n ? -1 : res) << nl;
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

