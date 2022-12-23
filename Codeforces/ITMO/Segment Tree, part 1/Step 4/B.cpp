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

ll r;

struct item {
    ll a[2][2];
    
    item() {
        fur(i, 0, 1)
            fur(j, 0, 1)
                a[i][j] = i == j;
    }

    item operator * (const item &oth) {
        item prod;
        prod.a[0][0] = prod.a[1][1] = 0;
        fur(k, 0, 1)
            fur(i, 0, 1)
                fur(j, 0, 1)
                    prod.a[i][j] = (prod.a[i][j] + a[i][k] * oth.a[k][j]) % r;
        return prod;
    }
};

struct SegTree {
    ll n;
    item id;
    vector<item> tree;

    SegTree(int N) {
        item tmp;
        init(N, tmp);
    }

    SegTree(int N, item x) {
        init(N, x);
    }

    void init(int N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n);
    }

    item query(ll node, ll lo, ll hi, ll ql, ll qh) {
        if(lo > qh || hi < ql)
            return id;
        if(lo >= ql && hi <= qh)
            return tree[node];

        ll mid = (lo + hi) / 2;
        item a = query(2*node, lo, mid, ql, qh);
        item b = query(2*node + 1, mid + 1, hi, ql, qh);

        return merge(a, b);
    }

    item query(ll ql, ll qh) {
        return query(1, 0, n - 1, ql, qh);
    }

    item merge(item l, item r) {
        return l * r;
    }
};

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);

    ll n, q;
    cin >> r >> n >> q;

    SegTree st(n);
    fur(i, 0, n - 1) {
        fur(j, 0, 1)
            fur(k, 0, 1)
                cin >> st.tree[st.n + i].a[j][k];
    }

    ruf(i, st.n - 1, 1)
        st.tree[i] = st.merge(st.tree[2*i], st.tree[2*i + 1]);

    while(q--) {
        ll l, r;
        cin >> l >> r;
        --l; --r;
        item ans = st.query(l, r);
        fur(i, 0, 1) {
            fur(j, 0, 1)
                cout << ans.a[i][j] << ' ';
            cout << nl;
        }
        cout << nl;
    }
}

