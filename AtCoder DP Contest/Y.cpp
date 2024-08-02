#include "bits/stdc++.h"
using namespace std;

const int mod = 1'000'000'007;

const int N = 3001;
const int H = 100'001;
int h, w, n;
int dp[N];
int fact[2*H];

struct Point {
    int X, Y;
    bool operator < (const Point& other) {
        if(X != other.X) return X < other.X;
        return Y < other.Y;
    }
}a[N];

int add(const int& x, const int& y) {
    return (((x + y) % mod) + mod) % mod;
}

int mul(const int& x, const int& y) {
    return (((x * 1LL * y) % mod) + mod) % mod;
}

int expo(int x, int p) {
    int res = 1;
    while(p) {
        if(p & 1) res = mul(x, res);
        x = mul(x, x);
        p /= 2;
    }
    return res;
}

int inv(int x) {
    return expo(x, mod - 2);
}

int divi(int num, int den) {
    return mul(num, inv(den));
}

void precompute() {
    fact[0] = 1;
    for(int i = 1; i < 2*H; ++i) fact[i] = mul(fact[i - 1], i);
}

int choose(int num, int den) {
    return divi(fact[num], mul(fact[num - den], fact[den]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    precompute();
    cin >> h >> w >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].X >> a[i].Y;
    }
    sort(a + 1, a + n + 1);

    dp[1] = choose(a[1].X + a[1].Y - 2, a[1].X - 1);
    for(int i = 2; i <= n; ++i) {
        dp[i] = choose(a[i].X + a[i].Y - 2, a[i].X - 1);
        for(int j = 1; j < i; ++j) {
            if(a[j].X > a[i].X || a[j].Y > a[i].Y) continue;
            // find A = ways from 1,1 to a[i] where the first square gone through is a[j]
            int A = mul(dp[j], choose(a[i].X - a[j].X + a[i].Y - a[j].Y, a[i].X - a[j].X));
            dp[i] = add(dp[i], -A);
        }
    }

    int ans = choose(h + w - 2, h - 1);
    for(int i = 1; i <= n; ++i) {
        dp[i] = mul(dp[i], choose(h - a[i].X + w - a[i].Y, h - a[i].X));
        ans = add(ans, -dp[i]);
    }
    cout << ans;
}
