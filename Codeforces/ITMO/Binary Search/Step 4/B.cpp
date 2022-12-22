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

using ld = long double;
ll n, m;
vector<pair<ll, ld>> adj[100001];
ll from[100001];

void output() {
    ll cur = n;
    vl ans;
    while(cur != -1) {
        ans.pb(cur);
        cur = from[cur];
    }
    reverse(all(ans));
    cout << (ll)ans.size() - 1 << nl;
    for(auto u : ans)
        cout << u << ' ';
}

bool good(ld x) {
    ld dist[n + 1];
    fur(i, 1, n) {
        dist[i] = 1e18;
    }
    from[1] = -1;
    dist[1] = 0;
    fur(a, 1, n - 1) {
        for(auto [b, w] : adj[a]) {
            if(dist[b] > dist[a] + w - x) {
                dist[b] = dist[a] + w - x;
                from[b] = a;
            }
        }
    }
    return dist[n] <= 0;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fur(i, 1, m) {
        ll a, b;
        ld c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }

    if(good(0)) {
        output();
        return 0;
    }

    ld lo = 0;
    ld hi = 100;
    fur(rep, 1, 100) {
        ld mid = (lo + hi) / 2;
        (good(mid) ? hi : lo) = mid;
    }
    good(hi);
    output();
    return 0;
}

