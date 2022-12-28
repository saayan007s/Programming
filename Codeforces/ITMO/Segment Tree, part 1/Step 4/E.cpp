#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const ll inf = 1e10;

using item = long long;

struct SegTree {
    ll n;
    item id = inf;
    vector<item> tree;

    SegTree(ll N) {
        init(N, id);
    }

    void init(ll N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, id);
    }

    void update(ll x, item val) {
        x += n;
        tree[x] = val;
        x /= 2;

        while(x >= 1) {
            tree[x] = min(tree[2*x], tree[2*x + 1]);
            x /= 2;
        }
    }

    item query(ll x, ll lx, ll rx, ll l, ll r, ll p) {
        if(lx > r || rx < l) {
            return 0;
        }
        if(l <= lx && rx <= r) {
            if(tree[x] > p) {
                return 0;
            }

            if(lx == rx) {
                tree[x] = inf;
                return 1;
            } else {
                ll d = (lx + rx) / 2;
                ll a = query(2*x, lx, d, l, r, p);
                ll b = query(2*x + 1, d + 1, rx, l, r, p);
                
                tree[x] = min(tree[2*x], tree[2*x + 1]);
                return a + b;
            }
        }
        ll d = (lx + rx) / 2;
        ll a = query(2*x, lx, d, l, r, p);
        ll b = query(2*x + 1, d + 1, rx, l, r, p);

        tree[x] = min(tree[2*x], tree[2*x + 1]);

        return a + b;
    }

    item query(ll ql, ll qh, ll p) {
        return query(1, 0, n - 1, ql, qh, p);
    }

    void print() {
        fur(i, 1, 2*n - 1) {
            if(__builtin_popcountll(i) == 1)
                cout << nl;
            if(tree[i] == inf)
                cout << "- ";
            else
            cout << tree[i] << ' ';
        }
        cout << nl;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    SegTree st(n);

    while(m--) {
        ll type;
        cin >> type;
        if(type == 1) {
            ll i, h;
            cin >> i >> h;
            st.update(i, h);
        } else {
            ll l, r, p;
            cin >> l >> r >> p;
            --r;
            ll res = st.query(l, r, p);
            // cout << nl;
            cout << res << nl;
            // cout << nl;
        }
        // st.print();
    }

}
