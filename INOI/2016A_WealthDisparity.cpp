#include "bits/stdc++.h"
using namespace std;

#define long int64_t
#define fr first
#define sc second
#define eb emplace_back
#define nl "\n"

const int N = 1e5L + 1;
int n;
long a[N];
vector<int> adj[N];
long ans = -1;

long dfs(int x) {
    long mn = a[x];
    for(int y : adj[x])
        mn = min(mn, dfs(y));
    ans = max(ans, a[x] - mn);
    return mn;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    if(n == 1) {
        cout << 0;
        return 0;
    }

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    int hojo = -1;
    for(int i = 0; i < n; ++i) {
        int p; cin >> p; --p;
        if(p == -2) hojo = i;
        else adj[p].eb(i);
    }

    dfs(hojo);
    cout << ans << nl;
}
