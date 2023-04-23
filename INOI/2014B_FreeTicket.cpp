#include "bits/stdc++.h"
using namespace std;

#define long long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int c, f;
    cin >> c >> f;

    vector<vector<int>> dist(c + 1, vector<int>(c + 1, -1));
    for(int i = 0; i < f; ++i) {
        int x, y, p;
        cin >> x >> y >> p;
        dist[x][y] = dist[y][x] = p;
    }

    for(int i = 1; i <= c; ++i) dist[i][i] = 0;

    for(int mid = 1; mid <= c; ++mid) {
        for(int src = 1; src <= c; ++src) {
            for(int dest = 1; dest <= c; ++dest) {
                if(dist[src][mid] != -1 && dist[mid][dest] != -1) {
                    int opt = dist[src][mid] + dist[mid][dest];
                    if(opt < dist[src][dest] || dist[src][dest] == -1)
                        dist[src][dest] = opt;
                }
            }
        }
    }

    int ans = -1;
    for(int src = 1; src <= c; ++src) {
        for(int dest = 1; dest <= c; ++dest) {
            ans = max(ans, dist[src][dest]);
        }
    }
    cout << ans;
}
