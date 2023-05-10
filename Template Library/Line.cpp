struct Line {
    int m, c;
    Line() {m = 0; c = inf;}
    Line(int a, int b) {m = a; c = b;}
    int val(int x) {return m*x + c;}
};
