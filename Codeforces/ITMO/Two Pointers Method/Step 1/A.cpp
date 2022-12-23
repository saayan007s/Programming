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

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vl a(n);
    for(auto &u : a) 
        cin >> u;
    vl b(m);
    for(auto &u : b)
        cin >> u;

    vl c(n + m);
    ll i = 0;
    ll j = 0;
    ll k = 0;
    while(k < n + m) {
        if(i < n && j < m) {
            if(a[i] < b[j])
                c[k++] = a[i++];
            else
                c[k++] = b[j++];
        } else if(j < m) {
            c[k++] = b[j++];
        } else {
            c[k++] = a[i++];
        }
    }
    for(auto u : c)
        cout << u << ' ';
}

