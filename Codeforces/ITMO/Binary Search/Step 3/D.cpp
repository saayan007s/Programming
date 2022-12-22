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

ll n, m, d;
vpl adj[100000 + 1];
vl par(100000 + 1, -1);

bool feas(ll k) {
    vl dist(n + 1, -1);
    queue<ll> q;

    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        ll a = q.front();
        q.pop();

        for(auto [b, w] : adj[a]) {
            if(w > k || dist[b] != -1)
                continue;
            dist[b] = dist[a] + 1;
            par[b] = a;
            q.push(b);
        }
    }
    return dist[n] <= d && dist[n] > 0;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;
    fur(i, 1, m) {
        ll a, b, c;
        cin >> a >> b >> c;
        if(a > b)
            swap(a, b);
        adj[a].pb(mp(b, c));
    }

    ll lo = -1;
    ll hi = 1e9 + 1;
    while(lo + 1 != hi) {
        ll mid = (lo + hi) / 2;
        (feas(mid) ? hi : lo) = mid;
    }
    feas(hi);

    if(hi == 1e9 + 1){
        cout << -1 << nl;
        return 0;
    }
    vl ans;
    ll cur = n;
    while(cur != -1) {
        ans.pb(cur);
        cur = par[cur];
    }
    reverse(all(ans));
    cout << ans.size() - 1 << nl;
    for(auto u : ans)
        cout << u << ' ';
}

