struct Query {
	int l, r, idx;
	
	inline pair<int, int> toPair() const {
		return make_pair(l / block, ((l / block) & 1) ? -r : r);
	}
};

inline bool operator<(const Query &a, const Query &b) {
	return a.toPair() < b.toPair();
}
