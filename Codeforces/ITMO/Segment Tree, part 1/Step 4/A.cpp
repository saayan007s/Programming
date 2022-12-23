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
    ll n;
    ll id;
    vl tree;

    SegTree(int N) {
        init(N, 0);
    }

    SegTree(int N, int x) {
        init(N, x);
    }

    void init(int N, int x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, 0);
    }

    void update(ll pos, ll val) {
        pos += n;
        tree[pos] = val;
        pos /= 2;

        while(pos >= 1) {
            tree[pos] = merge(tree[2*pos], tree[2*pos + 1]);
            pos /= 2;
        }
    }

    ll query(ll node, ll lo, ll hi, ll ql, ll qh) {
        if(lo > qh || hi < ql)
            return 0;
        if(lo >= ql && hi <= qh)
            return tree[node];

        ll mid = (lo + hi) / 2;
        ll a = query(2*node, lo, mid, ql, qh);
        ll b = query(2*node + 1, mid + 1, hi, ql, qh);
        return merge(a, b);
    }

    ll query(ll ql, ll qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    ll merge(ll l, ll r) {
        return l + r;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    SegTree a(n);
    SegTree b(n);
    fur(i, 0, n - 1) {
        cin >> a.tree[a.n + i];
        if(i % 2 == 1)
            a.tree[a.n + i] = -a.tree[a.n + i];
        b.tree[b.n + i] = -a.tree[a.n + i];
    }
    ruf(i, a.n - 1, 0) {
        a.tree[i] = a.merge(a.tree[2*i], a.tree[2*i + 1]);
        b.tree[i] = b.merge(b.tree[2*i], b.tree[2*i + 1]);
    }

    ll q;
    cin >> q;
    while(q--) {
        ll op;
        cin >> op;
        if(op == 0) {
            ll i, j;
            cin >> i >> j;
            --i;
            if(i % 2 == 1)
                j = -j;
            a.update(i, j);
            b.update(i, -j);
        } else {
            ll l, r;
            cin >> l >> r;
            --l; --r;
            cout << (l%2 == 0 ? a.query(l, r) : b.query(l, r)) << nl;
        }
    }
}

