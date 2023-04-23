#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int a[n];
    for(int &i : a) cin >> i;

    multiset<int, greater<int>> s;
    for(int i = 0; i < n; ++i)
        s.insert(a[i] + i + 1);

    cout << *s.begin() << ' ';
    for(int i = n - 1; i > 0; --i) {
        s.erase(s.find(a[i] + i + 1));
        s.insert(a[i] - n + 1 + i);
        cout << *s.begin() + n - i << ' ';
    }
}
