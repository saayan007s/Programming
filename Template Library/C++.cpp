#include "bits/stdc++.h"
using namespace std;

using ll = long long;

#define eb emplace_back
#define fr first
#define sc second
#define mp make_pair

const char nl = '\n';
bool dbg = 0;

void solve() {
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

#ifdef local
    dbg = 1;
#endif

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; ++i) {
        if(dbg) {
            cout << endl;
            cout << "Case #" << i << endl;
        }
        solve();
    }
    return 0;
}
