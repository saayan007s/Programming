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

ll n, m, k;
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

    cin >> n >> m >> k;
    fur(i, 0, m - 1) {
        ll a, b;
        cin >> a >> b;
    }
    par = vl(n + 1);
    sz = vl(n + 1, 1);
    iota(all(par), 0);
    tuple<char, ll, ll> q[k];
    fur(i, 0, k - 1) {
        ll a, b;
        string s;
        cin >> s >> a >> b;
        q[i] = tie(s[0], a, b);
    }
    vector<string> val = {"NO", "YES"};
    vector<string> ans;
    ruf(i, k - 1, 0) {
        char c; ll a, b;
        tie(c, a, b) = q[i];
        /* cout << c << ' ' << a << ' ' << b << nl; */
        if(c == 'a') {
            ans.pb(val[find(a) == find(b)]);
        } else {
            unite(a, b);
        }
    }
    reverse(all(ans));
    for(auto u : ans)
        cout << u << nl;
}

