struct Edge {
    int u, v, wt;
    int id;

    bool operator < (const Edge &other) {
        return wt < other.wt;
    }

    void print() {
        cout << u << ' ' << v << ' ' << wt << ' ' << id << nl;
    }
};
