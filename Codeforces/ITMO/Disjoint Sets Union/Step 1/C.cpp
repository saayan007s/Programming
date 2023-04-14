// https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/C
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
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll n, m;
// ll k;
struct UFDS {
    vl sz;
    vl lnk;
    vl val;

    UFDS(ll N) {
        sz = vl(N, 1);
        lnk = vl(N, 0);
        iota(all(lnk), 0);
        val = vl(N, 0);
    }

    ll find(ll a) {
        if(a == lnk[a]) {
            return a;
        }

        ll par = lnk[a];
        ll rep = find(par);

        if(lnk[a] != rep)
            val[a] += val[par];
        lnk[a] = rep;
        return rep;
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
        val[b] -= val[a];
    }
    
    void add(ll x, ll v) {
        x = find(x);
        val[x] += v;
    }
    
    ll get(ll a) {
        find(a);
        if(a == find(a)) {
            return val[a];
        } else {
            return val[a] + val[lnk[a]];
        }
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    UFDS uf(n + 1);
    // UFDS uf(n + m + 1);
    // k = n + 1;

    fur(rep, 1, m) {
        string s;
        cin >> s;
        if(s[0] == 'j') {
            ll x, y;
            cin >> x >> y;
            uf.unite(x, y);
        } else if(s[0] == 'a') {
            ll x, v;
            cin >> x >> v;
            uf.add(x, v);
        } else {
            ll x;
            cin >> x;
            cout << uf.get(x) << nl;
        }
    }
}

