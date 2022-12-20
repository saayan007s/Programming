struct Edge {
    ll u, v, wt;
    ll id;

    bool operator < (const Edge &other) {
        return wt < other.wt;
    }

    void print() {
        cout << u << ' ' << v << ' ' << wt << ' ' << id << nl;;
    }
};
