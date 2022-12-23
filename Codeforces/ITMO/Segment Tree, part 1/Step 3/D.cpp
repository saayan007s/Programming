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

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    SegTree st(2*n, 0);
    vl a(2 * n);
    vl right(n, -1);
    vl left(n, -1);
    fur(i, 0, 2*n - 1) {
        cin >> a[i];
        --a[i];
        if(left[a[i]] == -1) {
            st.update(i, -1);
            left[a[i]] = i;
        }
        else {
            st.update(i, 1);
            right[a[i]] = i;
        }
    }

    vl ans(n);
    ruf(i, 2*n - 1, 0) {
        ll j = a[i];
        if(i == left[j]) {
            ans[j] = st.query(left[j], right[j]);
            st.update(left[j], 1);
            st.update(right[j], -1);
        }
    }
    for(auto u : ans)
        cout << u << ' ';
}

