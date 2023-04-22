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
 
ll n, q;
vl fen;
vl x;
 
void update(ll pos, ll val) {
    while(pos < n + 2) {
        fen[pos] += val;
        pos += pos & (-pos);
    }
}
 
ll sum(ll pos) {
    ll ans = 0;
    while(pos >= 1) {
        ans += fen[pos];
        pos -= pos & -pos;
    }
    return ans;
}
 
void solve()
{
    /* taking input */
    cin >> n >> q;
    x.resize(n + 1);
    fur(i, 1, n)
        cin >> x[i];
    vpl qu(q);
    fur(i, 0, q - 1)
        cin >> qu[i].fr >> qu[i].sc;
 
    /* solving the problem */
    vl order(q);
    iota(all(order), 0);
    sort(all(order), [&] (ll left, ll right) {
        return qu[left] > qu[right];
    });
    vl ans(q);
    fen.resize(n + 2);
    map<ll, ll> prev;
    vl next(n + 2);
    next[n + 1] = n + 1;
    ruf(i, n, 1) {
        ll j = prev[x[i]];
        if(j == 0) {
            next[i] = n + 1;
        } else {
            next[i] = j;
        }
        prev[x[i]] = i;
    }
 
    ll l = n + 1;
    /* vl val(n + 2); */
    fur(i, 0, q - 1) {
        ll j = order[i];
        /* cout << qu[j].fr << ' ' << qu[j].sc << nl; */
        while(l != qu[j].fr) {
            --l;
            update(l, 1);
            update(next[l], -1);
            /* val[l] += 1; */
            /* val[next[l]] -= 1; */
        }
        /* fur(i, 1, n) */
        /*     cout << val[i] << ' '; */
        /* cout << nl; */
        /* cout << nl; */
        ans[j] = sum(qu[j].sc);
    }
    for(auto u : ans)
        cout << u << nl;
}
 
int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
	ll t = 1;
    /* cin >> t; */
    while(t--)
    {
        solve();
    }
}
 
