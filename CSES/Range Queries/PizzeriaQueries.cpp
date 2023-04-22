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
#define left first
#define right second
 
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
        tree = vector<item>(2 * n, id);
    }
 
    void update(ll pos, ll p) {
        pos += n;
        tree[pos] = {p, p};
        ll width = 1;
        pos /= 2;
 
        while(pos >= 1) {
            tree[pos] = comb(tree[2*pos], tree[2*pos + 1], width);
            pos /= 2;
            width *= 2;
        }
    }
 
    ll lhs(ll node, ll lo, ll hi, ll pos) {
        /* cout << node << ' '; */
        if(lo >= pos) {
            /* cout << "inf" << nl; */
            return 1e11;
        }
 
        if(hi < pos) {
            /* cout << tree[node].right + abs(hi - pos); */
            return tree[node].right + abs(hi - pos);
        }
 
        ll mid = (lo + hi) / 2;
        ll a = lhs(2*node, lo, mid, pos);
        ll b = lhs(2*node + 1, mid + 1, hi, pos);
 
        return min(a, b);
    }
 
    ll rhs(ll node, ll lo, ll hi, ll pos) {
        if(hi <= pos)
            return 1e11;
 
        if(lo > pos) {
            return tree[node].left + abs(pos - lo);
        }
 
        ll mid = (lo + hi) / 2;
        ll a = rhs(2*node, lo, mid, pos);
        ll b = rhs(2*node + 1, mid + 1, hi, pos);
 
        return min(a, b);
    }
 
    ll query(ll pos) {
        ll a = lhs(1, 0, n - 1, pos);
        ll b = rhs(1, 0, n - 1, pos);
        ll c = tree[n + pos].left;
        /* cout << a << ' ' << c << ' ' << b << nl; */
 
        return min({a, b, c});
    }
 
    item comb(item l, item r, ll width) {
        item ans;
        ans.left = min(l.left, r.left + width);
        ans.right = min(r.right, l.right + width);
        return ans;
    }
 
    void print() {
        fur(i, 1, 2*n - 1) {
            cout << tree[i].left << "/" << tree[i].right << "; ";
            if(!(i & (i + 1)))
                    cout << nl;
        }
    }
};
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, q;
    cin >> n >> q;
    
    SegTree st(n, {1e11, 1e11});
    fur(i, 0, n - 1) {
        ll p;
        cin >> p;
        st.update(i, p);
    }
    /* st.print(); */
 
    while(q--) {
        ll op;
        cin >> op;
        if(op == 1) {
            ll k, x;
            cin >> k >> x;
            st.update(--k, x);
        } else {
            ll k;
            cin >> k;
            --k;
            cout << st.query(k) << nl;
        }
    }
}
