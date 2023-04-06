// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];

    ll dp[4][n + 2][m + 2];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            dp[0][i][j] = max(dp[0][i][j + 1], dp[0][i + 1][j]) + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[1][i][j] = max(dp[1][i][j - 1], dp[1][i - 1][j]) + a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            dp[2][i][j] = max(dp[2][i][j + 1], dp[2][i - 1][j]) + a[i][j];
        }
    }

    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            dp[3][i][j] = max(dp[3][i][j - 1], dp[3][i + 1][j]) + a[i][j];
        }
    }

    ll ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        for (int j = 2; j <= m - 1; j++) {
            // 1|2
            // ---
            // 3|0
            ans = max(ans, dp[0][i][j + 1] + dp[1][i][j - 1] + dp[2][i - 1][j] + dp[3][i + 1][j]);
            ans = max(ans, dp[0][i + 1][j] + dp[1][i - 1][j] + dp[2][i][j + 1] + dp[3][i][j - 1]);
        }
    }

    cout << ans << endl;

    return 0;
}
