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
            return id;
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

struct dt{
    ll num, l, r;
    dt() {
        num = l = r = -1;
    }
    dt(ll a, ll b, ll c) {
        num = a;
        l = b;
        r = c;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vl a(2 * n);
    fur(i, 0, 2*n - 1) {
        cin >> a[i];
        --a[i];
    }

    SegTree st(2*n, 0);
    vl ans(n);
    vl right(n, -1);
    ruf(i, 2*n - 1, 0) {
        if(right[a[i]] == -1) {
            right[a[i]] = i;
            continue;
        }
        ans[a[i]] = st.query(i, right[a[i]]);
        st.update(right[a[i]], 1);
    }
    for(auto u : ans)
        cout << u << ' ';
}

