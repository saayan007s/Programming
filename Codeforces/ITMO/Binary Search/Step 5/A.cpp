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

ll n, k;
ll l[51], r[51];

bool good(ll x) {
    ll cnt = 0;
    fur(i, 1, n) {
        if(x > l[i]) {
            if(x > r[i])
                cnt += (r[i] - l[i] + 1);
            else
                cnt += x - l[i];
        }
    }
    return cnt <= k;
}
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fur(i, 1, n)
        cin >> l[i] >> r[i];
    
    ll lo = -1;
    while(!good(lo))
        lo *= 2;
    ll hi = 1;
    while(good(hi))
        hi *= 2;

    while(lo + 1 != hi) {
        ll m = (lo + hi) / 2;
        (good(m) ? lo : hi) = m;
    }
    cout << lo << nl;
}

