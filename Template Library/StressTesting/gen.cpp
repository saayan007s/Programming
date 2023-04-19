#include "bits/stdc++.h"
using namespace std;

#define nl "\n"

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(signed argv, char *argc[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    srand(atoi(argc[1]));
}
