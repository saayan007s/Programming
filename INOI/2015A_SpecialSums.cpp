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

    long n;
    cin >> n;
    long a[n + 1], b[n + 1];
    for(long i = 1; i <= n; ++i) cin >> a[i];
    for(long i = 1; i <= n; ++i) cin >> b[i];

    const long inf = 1e16;
    long res = -inf;
    b[0] = 0;
    for(long i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }

    auto ssum = [&](long l, long r) {
        return (long)(l == r ? a[l] : a[r] + a[l] + b[r - 1] - b[l]);
    };

    long l = 1;
    for(long r = 1; r <= n; ++r) {
        res = max({res, a[r], ssum(l, r)});
        if(a[r] > a[l] + b[r] - b[l])
            l = r;
    }

    long best[n + 1];
    best[1] = a[1];
    for(long i = 2; i <= n; ++i) {
        best[i] = max(best[i - 1], a[i] + b[i - 1]);
    }

    for(long i = n; i > 1; --i) {
        res = max(res, a[i] + b[n] - b[i] + best[i - 1]);
    }

    cout << res;
}
