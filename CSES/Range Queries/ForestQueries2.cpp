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
 
ll n, q;
ll ft[1001][1001] = {};
int s[1001][1001] = {};
 
void upd(ll x, ll y, ll u) {
    for(ll i = x; i <= n; i += (i & -i)) {
        for(ll j = y; j <= n; j += (j & -j)) {
            ft[i][j] += u;
        }
    }
}
 
ll qry(ll x, ll y) {
    ll res = 0;
    for(ll i = x; i > 0; i -= (i & -i)) {
        for(ll j = y; j > 0; j -= (j & -j)) {
            res += ft[i][j];
        }
    }
    return res;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> q;
 
    fur(i, 1, n) {
        fur(j, 1, n) {
            char c;
            cin >> c;
            if(c == '*') {
                upd(i, j, 1);
                s[i][j] = 1;
            }
        }
    }
    
    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            ll x, y;
            cin >> x >> y;
            upd(x, y, (s[x][y] == 1 ? -1 : 1));
            s[x][y] = 1 - s[x][y];
        } else {
            ll r, c, R, C;
            cin >> r >> c >> R >> C;
            ll res = qry(R, C) - qry(R, c - 1) - qry(r - 1, C) + qry(r - 1, c - 1);
            cout << res << nl;
        }
    }
}
