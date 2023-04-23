#include "bits/stdc++.h"
using namespace std;

#define long int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int r, c, n;
    cin >> r >> c >> n;

    set<pair<int, int>> pat;
    map<pair<int, int>, bool> vis;

    for(int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pat.insert({x, y});
    }

    long res = 0;
    for(auto [x, y] : pat) {
        if(vis[{x, y}]) continue;
        vis[{x, y}] = 1;
        long opt = 0;
        queue<pair<int, int>> q;
        q.push({x, y});

        while(!q.empty()) {
            int u = q.front().fr;
            int v = q.front().sc;
            q.pop();
            for(int du : {-1, 0, 1}) {
                for(int dv : {-1, 0, 1}) {
                    if(abs(du) == abs(dv)) continue;
                    if(vis[{u + du, v + dv}]) continue;
                    if(!pat.count({u + du, v + dv})) {
                        ++opt; continue;
                    }
                    q.push({u + du, v + dv});
                    vis[{u + du, v + dv}] = 1;
                }
            }
        }

        res = max(res, opt);
    }

    cout << res;
}
