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

ll n, m;
vl par, sz;

ll find(ll a) {
    return a == par[a] ? a : par[a] = find(par[a]);
}

void unite(ll a, ll b) {
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    if(sz[a] > sz[b])
        swap(a, b);
    par[a] = b;
    sz[b] += sz[a];
    return;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    par = vl(n + 1);
    sz = vl(n + 1, 1);
    iota(all(par), 0);
    while(m--) {
        string s;
        cin >> s;
        ll a, b;
        cin >> a >> b;
        if(s[0] == 'u') {
            unite(a, b);
        } else {
            cout << (find(a) == find(b) ? "YES" : "NO") << nl;
        }
    }
}

