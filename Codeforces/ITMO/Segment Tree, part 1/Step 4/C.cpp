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

struct item {
    ll cnt[41];
    ll inv;
    ll val;

    item() {
        val = 0;
        inv = 0;
        fur(i, 0, 40)
            cnt[i] = 0;
    }
    
    item(ll a) {
        val = a;
        inv = 0;
        fur(i, 0, 40)
            cnt[i] = (i >= val ? 1 : 0);
    }
};

struct SegTree {
    ll n;
    item id;
    vector<item> tree;

    SegTree(ll N) {
        init(N, id);
    }

    SegTree(ll N, item x) {
        init(N, x);
    }

    void init(ll N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, 0);
    }

    void update(ll pos, ll val) {
        pos += n;
        tree[pos] = item(val);

        pos /= 2;

        while(pos >= 1) {
            tree[pos] = merge(tree[2*pos], tree[2*pos + 1]);
            pos /= 2;
        }
    }

    item query(ll ql, ll qh) {
        ll l = ql + n;
        ll r = qh + n;
        item ansl;
        item ansr;
        while(l <= r) {
            if(l%2 == 1) {
                ansl = merge(ansl, tree[l++]);
            }
            if(r%2 == 0) {
                ansr = merge(tree[r--], ansr);
            }
            l /= 2;
            r /= 2;
        }
        return merge(ansl, ansr);
    }

    item merge(item l, item r) {
        item ans;
        ans.inv = l.inv + r.inv;
        fur(i, 1, 40) {
            ans.cnt[i] = l.cnt[i] + r.cnt[i];
            ans.inv += (l.cnt[40] - l.cnt[i]) * (r.cnt[i] - r.cnt[i - 1]); 
            // #elements in l with value > i times #elements in r with val = i
        }
        return ans;
    }

    void print() {
        fur(i, 1, 2*n - 1) {
            cout << tree[i].inv << ' ';
            if(!(i&(i + 1)))
                cout << nl;
        }
        cout << nl << nl;
    }
};

void solve()
{
    /* taking input */
    ll n, q;
    cin >> n >> q;
    vl a(n + 1);
    fur(i, 0, n - 1)
        cin >> a[i];

    /* cout << "array a" << nl; */
    /* for(auto u : a) */
    /*     cout << u << ' '; */
    /* cout << nl; */
    /* solving the problem */
    SegTree st(n);
    fur(i, 0, n - 1) {
        st.tree[st.n + i] = item(a[i]);
    }
    ruf(i, st.n - 1, 1) {
        st.tree[i] = st.merge(st.tree[2*i], st.tree[2*i + 1]);
    }
    /* cout << "inversion segtree" << nl; */
    /* st.print(); */

    while(q--) {
        ll type, x, y;
        cin >> type >> x >> y;
        if(type == 1) {
            --x; --y;
            cout << st.query(x, y).inv << nl;
        } else {
            st.update(x - 1, y);
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

