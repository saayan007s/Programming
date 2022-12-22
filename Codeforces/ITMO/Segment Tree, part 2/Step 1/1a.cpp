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

    void update(ll node, ll lo, ll hi, ll ql, ll qh, ll val) {
        if(lo > qh || hi < ql)
            return;
        if(lo >= ql && hi <= qh) {
            tree[node] += val;
            return;
        }

        ll mid = (lo + hi) / 2;
        update(2*node, lo, mid, ql, qh, val);
        update(2*node + 1, mid + 1, hi, ql, qh, val);
    }

    void update(ll l, ll r, ll v) {
        update(1, 0, n - 1, l, r, v);
    }

    ll query(ll node, ll lo, ll hi, ll pos) {
        if(lo > pos || hi < pos)
            return 0;
        if(lo == hi)
            return tree[node];

        ll mid = (lo + hi) / 2;
        ll a = query(2*node, lo, mid, pos);
        ll b = query(2*node + 1, mid + 1, hi, pos);

        return tree[node] + merge(a, b);
    }

    ll query(ll i) {
        return query(1, 0, n - 1, i);
    }

    ll merge(ll l, ll r) {
        return l + r;
    }
    
    void print() {
        fur(i, 1, 2*n - 1) {
            cout << tree[i] << ' ';
            if(!(i & (i + 1)))
                cout << nl;
        }
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    SegTree st(n, 0);
    ll q;
    cin >> q;

    while(q--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            /* cout << op << ' ' << l << ' ' << r << ' ' << v << nl; */
            --r;
            st.update(l, r, v);
        } else {
            ll i;
            cin >> i;
            /* cout << op << ' ' << i << nl; */
            cout << st.query(i) << nl;
        }
        /* st.print(); */
    }
}

