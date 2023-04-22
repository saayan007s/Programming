#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pi = pair<int, int>;
using pl = pair<long long, long long>;
using vi = vector<int>;
using vl = vector<long long>;
using vpi = vector<pair<int, int>>;
using vpl = vector<pair<long long, long long>>;
 
#define fur(i, a, b) for(ll i = a; i <= (ll)b; ++i)
#define ruf(i, a, b) for(ll i = a; i >= (ll)b; --i)
#define fr first 
#define sc second
#define mp make_pair
#define pb emplace_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    iset<pl> s;
    ll n, q;
    cin >> n >> q;
    ll p[n + 1];
    fur(i, 1, n) {
        cin >> p[i];
        s.insert({p[i], i});
    }
 
    while(q--) {
        char c;
        cin >> c;
        if(c == '!') {
            ll k, x;
            cin >> k >> x;
            s.erase({p[k], k});
            p[k] = x;
            s.insert({p[k], k});
        } else {
            ll a, b;
            cin >> a >> b;
            ll l = s.order_of_key(mp(b, n + 1));
            ll r = s.order_of_key(mp(a - 1, n + 1));
            cout << l - r << nl;
        }
    }
}
