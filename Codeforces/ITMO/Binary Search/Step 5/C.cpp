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

int n, k;
int a[100001];
int b[100001];

ll count(ll x) {
    ll cnt = 0;
    ll j = 0;
    ruf(i, n, 1) {
        while(j + 1 <= n && a[i] + b[j + 1] < x) {
            ++j;
        }
        if(j != 0 && a[i] + b[j] < x)
            cnt += j;
        /* cout << j << ' '; */
    }
    /* cout << nl; */
    return cnt;
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    fur(i, 1, n)
        cin >> a[i];
    fur(i, 1, n)
        cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);

    /* cout << count(9) << nl << count(10) << nl; */
    ll lo = 2;
    ll hi = 2e9 + 1;
    while(lo + 1 != hi) {
        ll mid = (lo + hi) / 2;
        (count(mid) < k ? lo : hi) = mid;
    }
    cout << lo << nl;
}

