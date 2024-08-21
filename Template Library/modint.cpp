const int mod = ;

int add(int x, int y) {
    if( ((x += y) %= mod) < 0) x += mod;
    return x;
}

int mul(int x, int y) {
    if( ((x *= y) %= mod) < 0) x += mod;
    return x;
}

int pwr(int x, int p) {
    int ret = 1;
    while(p) {
        if(p % 2) ret = mul(ret, x);
        x = mul(x, x);
        p /= 2;
    }
    return ret;
}

int inv(int x) {
    return pwr(x, mod - 2);
}

int divi(int x, int y) {
    return mul(x, inv(y));
}
