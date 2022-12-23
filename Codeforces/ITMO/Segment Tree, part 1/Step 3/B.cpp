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
        tree.resize(2*n, id);
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

    ll query(ll node, ll lo, ll hi, ll k) {
        if(tree[node] < k)
            return -1;
        if(lo == hi)
            return lo;

        ll mid = (lo + hi) / 2;
        ll res = query(2*node + 1, mid + 1, hi, k);
        if(res == -1)
            res = query(2*node, lo, mid, k - tree[2*node + 1]);
        return res;
    }

    ll query(ll k) {
        return query(1, 0, n - 1, k);
    }

    ll merge(ll l, ll r) {
        return l + r;
    }

    void print() {
        fur(i, 1, n)
        {
            cout << tree[i] << ' ';
            if(!(i & (i + 1)))
                cout << nl;
        }
        cout << nl;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    SegTree st(n, 0);
    vl p(n);
    fur(i, 0, n - 1) 
        cin >> p[i];

    fur(i, 0, n - 1) {
        st.tree[st.n + i] = 1;
    }
    ruf(i, st.n - 1, 0)
        st.tree[i] = st.merge(st.tree[2*i], st.tree[2*i + 1]);

    vl ans(n);
    ruf(i, n - 1, 0) {
        ans[i] = st.query(p[i] + 1) + 1;
        st.update(ans[i] - 1, 0);
    }
    fur(i, 0, n - 1) 
        cout << ans[i] << ' ';
}
