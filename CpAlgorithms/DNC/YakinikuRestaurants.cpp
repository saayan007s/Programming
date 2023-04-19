#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<ll, ll>>;

#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    ll a[n + 1] = {};
    fur(i, 1, n - 1) cin >> a[i];

    ll b[n + 1][m + 1] = {}, c[n + 1][m + 1] = {};

    fur(i, 1, n) fur(j, 1, m) cin >> b[i][j];

    fur(j, 1, m) {
        stack<ll> st;
        ruf(i, n, 1) {
            while(!st.empty() && b[i][j] >= b[st.top()][j]) st.pop();
            if(st.empty()) c[i][j] = -1;
            else c[i][j] = st.top();
            st.push(i);
        }
    }

    ll inc[n + 1] = {};
    bool taken[n + 1][m + 1] = {};

    ll res = 0;
    fur(i, 1, n) {
        ll ans = 0;
        fur(j, 1, m) {
            ans += b[i][j];
            ll x = i;
            while(!taken[x][j]) {
                ll k = c[x][j];
                if(k == -1) break;
                inc[k] += (b[k][j] - b[x][j]);
                taken[x][j] = 1;
                x = c[x][j];
            }
        }

        res = max(res, ans);
        fur(j, i+1, n) {
            ans -= a[j - 1];
            ans += inc[j];
            res = max(res, ans);
        }

        fur(j, 1, m) {
            ll k = c[i][j];
            if(k != -1) inc[k] -= (b[k][j] - b[i][j]);
        }
    }

    cout << res << nl;
}
