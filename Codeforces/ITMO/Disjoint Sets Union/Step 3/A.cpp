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
#define nl endl
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

ll ans = 0;
struct UFDS {
    vl sz;
    vl lnk;
    stack<tuple<ll, ll, bool>> st;

    UFDS(ll N) {
        sz = vl(N, 1);
        lnk = vl(N);
        iota(all(lnk), 0);
    }

    ll find(ll a) {
        if(a == lnk[a]) {
            return a;
        }

        return find(lnk[a]);
    }

    bool same(ll a, ll b) {
        return find(a) == find(b);
    }

    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);

        if(a == b) {
            return 0;
        }

        if(sz[a] < sz[b])
            swap(a, b);

        st.push({b, sz[a], 0});
        lnk[b] = a;
        sz[a] += sz[b];

        return 1;
    }
    
    void rollback() {
        ll ch, szp;
        bool per;

        tie(ch, szp, per) = st.top();
        st.pop();

        while(!per) {
            sz[lnk[ch]] = szp;
            lnk[ch] = ch;

            ++ans;

            tie(ch, szp, per) = st.top();
            st.pop();
        }
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    ans = n;
    UFDS uf(n + 1);
    while(m--) {
        string s;
        cin >> s;
        if(s[0] == 'p') {
            uf.st.push({0, 0, 1});
        } else if(s[0] == 'u') {
            ll a, b;
            cin >> a >> b;

            ans -= (uf.unite(a, b) ? 1ll : 0ll);
            cout << ans << nl;
        } else {
            uf.rollback();
            cout << ans << nl;
        }
     }
}
