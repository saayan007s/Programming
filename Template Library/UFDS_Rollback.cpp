struct UFDS {
    int n;
    vector<int> sz, lnk;
    int grps;
    stack<pair<int, int>> st;

    UFDS(int N, int g) {
        n = N;
        grps = g;
        lnk.resize(n); iota(lnk.begin(), lnk.end(), 0);
        sz.resize(n, 1);
    }

    int find(int a) {
        return (a == lnk[a] ? a : find(lnk[a]));
    }

    void unite(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return;
        if(sz[a] < sz[b]) swap(a, b);
        lnk[b] = a;
        sz[a] += sz[b];
        st.push({b, a});
        --grps;
    } 

    void persist() {
        st.push({-1, -1});
    }

    void rollback() {
        while(!st.empty() && st.top().fr != -1) {
            int b = st.top().fr, a = st.top().sc;
            lnk[b] = b;
            sz[a] -= sz[b];
            ++grps;
            st.pop();
        }
        if(!st.empty()) st.pop();
    }
};
