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
#define x first 
#define y second
#define mp make_pair
#define pb emplace_back
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

struct Line {
    ll m, c;
    
    Line(ll m, ll c) : m(m), c(c) {}

    ll intersect(Line &other) {
        return (c - other.c + other.m - m - 1) / (other.m - m);
    }

    ll val(ll x) {
        return m * x + c;
    }
};

bool operator<(Line other, Line another) {
    return other.m < another.m;
}

struct CHT {
    deque<pair<Line, ll>> dq;  

    void insert(ll m, ll c) {
        Line nx(m, c);

        if(dq.empty()) {
            dq.pb(nx, 0);
            return;
        }

        while(!dq.empty() && nx.intersect(dq.back().first) < dq.back().second) {
            dq.pop_back();
        }

        if(!dq.empty()) {
            dq.pb(nx, nx.intersect(dq.back().first));
            return;
        }

        dq.pb(nx, 0);
    }

    ll query(ll x) {
        ll m = dq.size();
        while(m > 1 && dq[1].second <= x) {
            dq.pop_front();
            --m;
        }
        return dq.front().first.val(x);
    }
};

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;

    vpl pts(n);
    for(auto &[x, y] : pts) {
        cin >> x >> y;
    }

    sort(all(pts));
    vpl tmp;
    ll max_y = pts[n - 1].y;
    tmp.pb(pts[n - 1]);
    ruf(i, n - 2, 0) {
        if(pts[i].y > max_y) {
            max_y = pts[i].y;
            tmp.pb(pts[i]);
        }
    }
    swap(tmp, pts);

    sort(all(pts), [&](pl lt, pl rt) {
        return lt.y > rt.y;
    });
    n = pts.size();

    CHT cht;
    ll ans[n] = {};
    cht.insert(pts[0].y, 0);
    ans[0] = cht.query(pts[0].x);

    fur(i, 1, n - 1) {
        cht.insert(pts[i].y, ans[i - 1]);
        ans[i] = cht.query(pts[i].x);
    }

    cout << ans[n - 1] << nl;
}
