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

const ll mxn = 1000;
ll n, m;
ll t[mxn + 1], z[mxn + 1], y[mxn + 1];
ll bal[mxn + 1];

bool good(ll time) {
    ll total = 0;
    fur(i, 1, n) {
        ll num_periods = time / (t[i]*z[i] + y[i]);
        ll remaining = time % (t[i]*z[i] + y[i]);

        bal[i] = num_periods * z[i] + min(z[i], remaining / t[i]);

        total += bal[i];
    }
    return total >= m;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    fur(i, 1, n) {
        cin >> t[i] >> z[i] >> y[i];
    }

    if(m == 0) {
        cout << 0 << nl;
        fur(i, 1, n)
            cout << 0 << ' ';
        return 0;
    }

    ll lo = 0;
    ll hi = 1;
    while(!good(hi))
        hi *= 2;

    while(lo + 1 != hi) {
        ll mid = (lo + hi) / 2;
        (good(mid) ? hi : lo) = mid;
    }
    good(hi);
    cout << hi << nl;
    ll cnt = 0;
    fur(i, 1, n) {
        if(cnt >= m) {
            cout << 0 << ' ';
        } else {
            if(cnt + bal[i] > m) {
                cout << m - cnt << ' ';
                cnt = m;
            }
            else {
                cout << bal[i] << ' ';
                cnt += bal[i];
            }
        }
    }
}
