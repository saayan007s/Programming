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

#define fr first 
#define sc second
#define pb push_back
#define mp make_pair

#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll n, q;
struct UFDS {
    vl sz;
    vl lnk;
    vl left, right;

    UFDS(ll N) {
        sz = vl(N + 1, 1);
        lnk = vl(N + 1);
        right = vl(N + 1);
        left = vl(N + 1);

        iota(all(lnk), 0);
        iota(all(right), 0);
        iota(all(left), 0);
    }

    ll find(ll a) {
        return (a == lnk[a] ? a : lnk[a] = find(lnk[a]));
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        if(sz[a] < sz[b])
            swap(a, b);

        lnk[b] = a;
        sz[a] += sz[b];
        left[a] = min(left[a], left[b]);
        right[a] = max(right[a], right[b]);

        return;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    UFDS uf(n), line(n);

    while(q--) {
        ll t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            uf.unite(x, y);
        } else if(t == 2) {
            ll i = x;
            while(i < y) {
                ll j = line.find(i + 1);
                uf.unite(i, j);
                line.unite(i, j);
                i = line.right[j];
            }
        } else {
            cout << (uf.same(x, y) ? "YES" : "NO") << nl;
        }
    }
}

