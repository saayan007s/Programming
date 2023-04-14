#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using vi = vector<int>;
using vl = vector<long long>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb emplace_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

struct UFDS {
    vl sz;
    vl lnk;

    UFDS(ll N) {
        sz = vl(N, 1);
        lnk = vl(N);
        iota(all(lnk), 0);
    }

    ll find(ll a) {
        if(a == lnk[a]) {
            return a;
        }

        return lnk[a] = find(lnk[a]);
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

        return;
    }
};

struct Edge {
    ll u, v, wt;

    bool operator < (const Edge &other) {
        return wt < other.wt;
    }

    void print() {
        // cout << u << ' ' << v << ' ' << wt << ' ' << id << nl;;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    Edge e[m];
    for(auto &[u, v, w] : e) {
        cin >> u >> v >> w;
    }
    sort(e, e + m);

    UFDS uf(n + 1);
    ll ans = 0;
    for(auto &[u, v, w] : e) {
        if(!uf.same(u, v)) {
            uf.unite(u, v);
            ans += w;
        }
    }
    cout << ans << nl;
}


