#include <bits/stdc++.h>
using namespace std;

struct CHT {
    struct Line {
        int64_t m, c;

        Line(int64_t a, int64_t b) {
            m = a;
            c = b;
        }

        int64_t intersect(Line &other) {
            return (c - other.c + other.m - m - 1) / (other.m - m);
        }

        int64_t val(int64_t x) {
            return m*x + c;
        }
    };

    deque<pair<Line, int64_t>> CH;

    void insert(int64_t m, int64_t c) {
        Line next = Line(m, c);
        if(CH.empty()) {
            CH.emplace_back(next, 0);
            return;
        }

        while(!CH.empty()) {
            Line prev = CH.back().first;
            int64_t x = CH.back().second;
            if(next.m == prev.m) {
                if(next.c > prev.c) {
                    return;
                }
            } else if(next.intersect(prev) > x) {
                break;
            }
            CH.pop_back();
        }

        if(CH.empty()) {
            CH.emplace_back(next, 0);
            return;
        }

        CH.emplace_back(next, next.intersect(CH.back().first));
    }

    int64_t query(int64_t x) {
        int64_t m = CH.size();
        while(m > 1 && CH[1].second <= x) {
            CH.pop_front();
            --m;
        }
        return CH.front().first.val(x);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; int64_t c;
    cin >> n >> c;
    int h[n];
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    int64_t dp[n];
    CHT cht;

    dp[0] = 0;
    for(int i = 1; i < n; ++i) {
        cht.insert(-2 * h[i - 1], dp[i - 1] + h[i - 1] * 1LL * h[i - 1]);
        dp[i] = h[i] * 1LL * h[i] + c + cht.query(h[i]);
    }

    cout << dp[n - 1];
}
