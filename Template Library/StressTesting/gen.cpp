#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include "bits/stdc++.h"
using namespace std;

#define nl "\n"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rand(int a, int b) {
    return a + rng() % (b - a + 1);
}

int main(signed argv, char *argc[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);

}

