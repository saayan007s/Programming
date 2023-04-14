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

ll n;
vl par, sz, mx, mn;

ll find(ll a) {
    return a == par[a] ? a : par[a] = find(par[a]);
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if(a == b || sz[a] == 0 || sz[b] == 0)
        return;
    if(sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    if((mx[a] + 1 > n ? 1 : mx[a] + 1) == mn[b]) {
        mx[a] = mx[b];
    } else
        mn[a] = mn[b];
    return;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    par.resize(n + 1);
    iota(all(par), 0);
    mx.resize(n + 1);
    iota(all(mx), 0);
    mn.resize(n + 1);
    iota(all(mn), 0);
    sz.resize(n + 1);

    fur(i, 1, n) {
        ll p;
        cin >> p;
        p = find(p);
        if(sz[p] != 0) {
            p = mx[p] + 1;
            if(p > n)
                p -= n;
        }
        ++sz[p];
        cout << p << ' ';

        ll lo = p - 1;
        if(lo < 1)
            lo += n;
        ll hi = p + 1;
        if(hi > n)
            hi -= n;

        unite(p, lo);
        unite(p, hi);
    }
}

