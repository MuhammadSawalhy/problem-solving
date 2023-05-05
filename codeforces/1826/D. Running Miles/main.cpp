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

void solve() {
    int n;
    cin >> n;
    ll b[n];

    for (int i = 0; i < n; i++)
        cin >> b[i];

    int inf = 1e9;
    int dp[n][3];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++)
            dp[i][j] = -inf;
    }

    for (int i = 0; i < n; i++) {
        if (i > 0)
            dp[i][0] = max(dp[i - 1][0], b[i] + i);
        else
            dp[i][0] = b[i] + i;
    }

    for (int i = 1; i < n; i++) {
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + b[i]);
    }

    int ans = -inf;
    for (int i = 2; i < n; i++) {
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + b[i] - i);
        ans = max(ans, dp[i][2]);
    }

    cout << ans << '\n';
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
