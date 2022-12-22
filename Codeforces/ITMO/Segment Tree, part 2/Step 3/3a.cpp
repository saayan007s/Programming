#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

const ll noch = -1e10;
struct item {
    ll val, upd, pref, suf, sum, mx;

    item() {
        val = pref = suf = sum = mx = 0;
        upd = noch;
    }

    item(ll a, ll b, ll c, ll d, ll e, ll f) {
        val = a;
        upd = b;
        pref = c;
        suf = d;
        sum = e;
        mx = f;
    }
};

struct lzst {
    ll n;
    item id;
    vector<item> tree;

    lzst(ll N) {
        init(N, id);
    }

    lzst(ll N, item x) {
        init(N, x);
    }

    void init(ll N, item x) {
        id = x;
        n = N;
        while(__builtin_popcountll(n) != 1) ++n;
        tree.resize(2*n, id);
    }

    item app(item x, ll ch, ll range) {
        if(ch == noch) {
            return x;
        }
        
        x.val = ch;
        x.upd = ch;
        x.pref = max(0ll, ch * range);
        x.suf = max(0ll, ch * range);
        x.sum = ch*range;
        x.mx = max(0ll, ch * range);
        return x;
    }

    void prop(ll x, ll lx, ll rx) {
        if(lx == rx) {
            tree[x].upd = noch;
            return;
        }       

        tree[2*x] = app(tree[2*x], tree[x].upd, (rx - lx + 1) / 2);
        tree[2*x + 1] = app(tree[2*x + 1], tree[x].upd, (rx - lx + 1) / 2);

        tree[x].upd = noch;
    }

    void mod(ll x, ll lx, ll rx, ll l, ll r, ll v) {
        prop(x, lx, rx);
        if(rx < l || r < lx)
            return;
        if(l <= lx && rx <= r) {
            tree[x] = app(tree[x], v, rx - lx + 1);
            return;
        }

        ll d = (lx + rx) / 2;
        mod(2*x, lx, d, l, r, v);
        mod(2*x + 1, d + 1, rx, l, r, v);

        tree[x] = merge(tree[2*x], tree[2*x + 1]);
    }

    void mod(ll l, ll r, ll v) {
        mod(1, 0, n - 1, l, r, v);
    }

    ll getAns(ll l, ll r, ll v) {
        mod(l, r, v);
        return tree[1].mx;
    }
    
    item merge(item l, item r) {
        item ans;

        ans.pref = max(l.pref, l.sum + r.pref);
        ans.suf = max(r.suf, l.suf + r.sum);
        ans.sum = l.sum + r.sum;
        ans.mx = max({l.mx, r.mx, l.suf + r.pref});

        return ans;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    lzst st(n);
    while(m--) {
        ll l, r, v;
        cin >> l >> r >> v;

        cout << st.getAns(l, r - 1, v) << nl;
    }
}

