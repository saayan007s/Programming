#include "bits/stdc++.h"
using namespace std;

#define long long long
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 301;
int n, k;
int p[N];
vector<int> id[N];
vector<int> adj[N];
bool vis[N] = {};
int res = 0;

bool family(int l, int r) {
    int cnt = 0;
    int il = 0, ir = 0;
    while(il < p[l] && ir < p[r]) {
        if(id[l][il] < id[r][ir]) ++il;
        else if(id[l][il] > id[r][ir]) ++ir;
        else ++cnt, ++ir;
    }

    return cnt >= k;
}

void dfs(int cur = 0) {
    vis[cur] = 1;
    ++res;
    for(int next : adj[cur])
        if(!vis[next])
            dfs(next);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> p[i];
        id[i].resize(p[i]);
        for(int &j : id[i])
            cin >> j;
        sort(id[i].begin(), id[i].end());
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(family(i, j)) {
                adj[i].eb(j);
                adj[j].eb(i);
            }
        }
    }

    dfs();
    cout << res;
}
