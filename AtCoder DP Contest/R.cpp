#include "bits/stdc++.h"
using namespace std;

const int mod = 1'000'000'007;
const int N = 50;

struct Matrix {
    int a[N][N];

    Matrix(int diag = 0) {
        for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) a[i][j] = (i == j ? diag : 0);
    }

    Matrix operator * (Matrix &other) {
        Matrix res;
        for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) {
            res.a[i][j] = 0;
            for(int x = 0; x < N; ++x) {
                res.a[i][j] += (a[i][x] * 1LL * other.a[x][j]) % mod;
                if(res.a[i][j] >= mod) res.a[i][j] -= mod;
            }
        }
        return res;
    }
    
    int sum() {
        int res = 0;
        for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) {
            res += a[i][j];
            if(res >= mod) res -= mod;
        }
        return res;
    }
};

Matrix expo(Matrix &mat, int64_t e) {
    Matrix res(1);
    while(e) {
        if(e & 1) res = res * mat;
        mat = mat * mat;
        e >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; int64_t k;
    cin >> n >> k;
    Matrix mat;
    for(int i = 0; i < N; ++i) for(int j = 0; j < N; ++j) mat.a[i][j] = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> mat.a[i][j];
    mat = expo(mat, k);
    cout << mat.sum();
    return 0;
}
