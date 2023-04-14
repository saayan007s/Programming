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
    vl dep;
    vl add;

    UFDS(ll N) {
        sz = vl(N, 1);
        add = vl(N, 1);
        lnk = vl(N);
        iota(all(lnk), 0);
        dep = vl(N);
    }

    ll find(ll a) {
        if(a == lnk[a]) {
            return a;
        }

        ll par = lnk[a];
        ll rep = find(par);
        if(par != rep) {
            add[a] += add[par];
            dep[a] += add[par];
            lnk[a] = rep;
        }
        return lnk[a] = rep;
    }

    ll get(ll a) {
        find(a);
        if(a == lnk[a]) {
            return dep[a];
        } else {
            return dep[a] + add[lnk[a]];
        }
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    void unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return;

        // if(sz[b] > sz[a]) {
            lnk[a] = b;
            sz[b] += a;
            add[a] = dep[b] + 1;
        // } else {
            // lnk[b] = a;
            // sz[a] += b;
            // --dep[b];
        // }
        return;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    UFDS uf(n + 1);
    while(m--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll a, b;
            cin >> a >> b;
            uf.unite(a, b);
        } else {
            ll c;
            cin >> c;
            cout << uf.get(c) << nl;
        }
    }
}


