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
    vl ene;

    UFDS(ll N) {
        sz = vl(N, 1);
        lnk = vl(N);
        iota(all(lnk), 0);
        ene = vl(N, -1);
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

    ll unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if(a == b)
            return a;

        if(sz[a] < sz[b])
            swap(a, b);

        lnk[b] = a;
        sz[a] += sz[b];

        return a;
    }

    void makeEnemies(ll a, ll b) {
        a = find(a);
        b = find(b);
        ll c = ene[a];  
        ll d = ene[b];

        if(c != -1) {
            b = unite(b, c);
        }
        if(d != -1) {
            a = unite(a, d);
        }

        ene[a] = b;
        ene[b] = a;
    }

    bool areFriends(ll a, ll b) {
        a = find(a);
        b = find(b);

        return ene[a] != b;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    UFDS uf(n + 1);
    ll shift = 0;
    while(m--) {
        ll q;
        cin >> q;
        ll a, b;
        cin >> a >> b;
        (a += shift) %= n;
        (b += shift) %= n;
        if(q == 0) {
            uf.makeEnemies(a, b);
        } else if(q == 1) {
            if(uf.areFriends(a, b)) {
                cout << "YES" << nl;
                (++shift) %= n;
            } else {
                cout << "NO" << nl;
            }
        }
    }
}


