struct Line {
    int m, c;

    Line(int a, int b) {
        m = a;
        c = b;
    }

    int isect(const Line &other) {
        return (c - other.c + other.m - m - 1) / (other.m - m);
    }

    int val(int x) {
        return m*x + c;
    }
};