// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int N = 2e5 + 5;
ll dp[N][2];
int n, s, a[N];
pair<int, int> b[N];

ll solve(int i, int y, bool prev) {
    if (i == n - 1) return 1LL * y * a[i];
    ll & res = dp[i][prev];
    if (~res) return res;

    res = 1e18;

    res = min(res, solve(i + 1, b[i].first, 0) + 1LL * y * b[i].second);
    res = min(res, solve(i + 1, b[i].second, 1) + 1LL * y * b[i].first);
    debug(i, prev, y, res, b[i]);

    return res;
}

void solve() {
    cin >> n >> s;

    debug(n, s);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= s) {
            b[i].first = 0;
            b[i].second = a[i];
        }
        else {
            b[i].first = s;
            b[i].second = a[i] - s;
        }

        debug(a[i], b[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++)
            dp[i][j] = -1;
    }

    cout << solve(1, a[0], 0) << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
