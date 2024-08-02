#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    int a[n]; for(int &i : a) cin >> i;

    bool win[k + 1] = {};
    win[0] = 0;
    for(int i = 1; i <= k; ++i) {
        for(int x : a) {
            if(x <= i && !win[i - x]) {
                win[i] = 1;
                break;
            }
        }
    }

    cout << (win[k] ? "First" : "Second");
}
