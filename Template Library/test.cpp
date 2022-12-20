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
#define pb push_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

struct Edge {
    ll u, v, wt;
    ll id;

    bool operator < (const Edge &other) {
        return wt < other.wt;
    }

    void print() {
        cout << u << ' ' << v << ' ' << wt << ' ' << id << nl;;
    }

    Edge(ll a, ll b, ll c, ll d) {
        u = a;
        v = b;
        wt = c;
        id = d;
    }

    Edge(ll a, ll b, ll c) {
        u = a;
        v = b;
        wt = c;
    }
    
    Edge(ll a, ll b) {
        u = a;
        v = b;
        wt = 1;
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    Edge a = {1, 2, 3, 4};
    a.print();
}

