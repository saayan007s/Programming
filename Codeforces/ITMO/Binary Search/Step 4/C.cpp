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

ll n, k;
pl a[100001];
ld ep = 1e-8;

bool good(ld x) {
    ld s = 0;
    sort(a + 1, a + n + 1, [&](pl l, pl r) {
        return l.fr - x*l.sc > r.fr - x*r.sc;
    });

    fur(i, 1, k) {
        s += (a[i].fr - x*a[i].sc);
    }
    return s >= ep;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    fur(i, 1, n) {
        cin >> a[i].fr >> a[i].sc;
    }


    ld lo = 1e-5;
    ld hi = 1;
    while(good(hi))
        hi *= 2;
    while(lo + ep < hi) {
        ld m = (lo + hi) / 2;
        (good(m) ? lo : hi) = m;
    }
    cout << setprecision(20) << lo << nl;
}

