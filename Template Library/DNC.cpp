// not tested at all
int n, k;
int cost[N][N];
int dp[N][K];
int inf;

void dnc(int lvl, int l, int r, int optl, int optr) {
    if(l > r) return;

    int mid = (l + r) / 2;
    pair<int, int> best = {inf, -1};

    for(int i = optl; i <= min(mid, optr); ++i) {
        best = min(best, {dp[i - 1][lvl - 1] + cost[i][mid], i});
    }

    dp[mid][lvl] = best.first;
    int opt = best.second;

    dnc(lvl, l, mid - 1, optl, opt);
    dnc(lvl, mid + 1, r, opt, optr);
}

void solve() {
    for(int i = 1; i <= n; ++i) {
        cost[i][i] = ;
        for(int j = i + 1; j <= n; ++j) {
            cost[i][j] = ;
        }
    }

    dp[0][0] = ;
    for(int i = 1; i <= n; ++i) {
        dp[i][0] = ;
    }

    for(int j = 1; j <= k; ++j) {
        dnc(j, 1, n, 1, n);
    }

    cout << dp[n][k];
}
