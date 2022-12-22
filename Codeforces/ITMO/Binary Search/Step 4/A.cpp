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

ll n, d;
ll a[100001];
using ld = long double;

pl good(ld x) {
    ld p[n + 1];
    pair<ld, ll> m[n + 1];
    p[0] = 0;
    m[0] = mp(0, 0);

    fur(i, 1, n) {
        p[i] = p[i - 1] + a[i] - x;
        if(p[i] < m[i - 1].fr)
            m[i] = mp(p[i], i);
        else m[i] = m[i - 1];

        if(i - d >= 0 && p[i] - m[i - d].fr >= 0)
            return mp(m[i - d].sc + 1, i);
    }
    return mp(-1ll, -1ll);
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> d; 
    fur(i, 1, n)
        cin >> a[i];

    ld lo = 0;
    ld hi = 101;
    fur(rep, 1, 100) {
        ld m = (lo + hi) / 2;
        (good(m).fr != -1 ? lo : hi) = m;
    }
    pl ans = good(lo);
    cout << ans.fr << ' ' << ans.sc << nl;
}

