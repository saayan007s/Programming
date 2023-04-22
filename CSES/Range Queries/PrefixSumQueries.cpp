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
 
typedef pl item;
#define sum first
#define pref second
 
struct SegTree {
    ll n;
    item id = {0, 0};
    vector<item> tree;
 
    SegTree(int N) {
        init(N, id);
    }
 
    SegTree(int N, item x) {
        init(N, x);
    }
 
    void init(int N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree = vector<item>(2 * n);
    }
 
    void update(ll pos, ll val) {
        pos += n;
        tree[pos].sum = val;
        tree[pos].pref = max((ll)0, tree[pos].sum);
        pos /= 2;
 
        while(pos >= 1) {
            tree[pos] = merge(tree[2*pos], tree[2*pos + 1]);
            pos /= 2;
        }
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
        item ans;
        ans.sum = l.sum + r.sum;
        ans.pref = max(l.pref, l.sum + r.pref);
        return ans;
    }
};
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, q;
    cin >> n >> q;
 
    SegTree st(n);
    fur(i, 0, n - 1) {
        cin >> st.tree[st.n + i].sum;
        st.tree[st.n + i].pref = max((ll)0, st.tree[st.n + i].sum);
    }
 
    ruf(i, st.n - 1, 1) {
        st.tree[i] = st.merge(st.tree[2*i], st.tree[2*i + 1]);
    }
 
    while(q--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll k, u;
            cin >> k >> u;
            --k;
            st.update(k, u);
        } else {
            ll a, b;
            cin >> a >> b;
            --a; --b;
            item ans = st.query(a, b);
            cout << ans.pref << nl;
        }
    }
}
