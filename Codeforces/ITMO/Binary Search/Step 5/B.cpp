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

ll count(ll x) {
    ll cnt = 0;
    fur(i, 1, n) {
        ll num = (x - 1) / i;
        if(num > n)
            num = n;
        if(num < 0)
            num = 0;
        cnt += num;
    }
    return cnt;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    
    ll lo = 1;
    ll hi = n*n + 1;

    while(lo + 1 != hi) {
        ll m = (lo + hi) / 2;
        /* (count(m) < k ? lo : hi) = m; */
        ll cnt = count(m);
        if(cnt < k)
            lo = m;
        else hi = m;
    }
    cout << lo << nl;
}

