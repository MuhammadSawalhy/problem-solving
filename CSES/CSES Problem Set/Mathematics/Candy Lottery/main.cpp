// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    long double dp[101][101] = {};
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][j] = dp[i - 1][j] * (j - 1) / k;
            dp[i - 1][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j] / k;
        }
    }

    long double ans = 0;

    for (int i = 1; i <= k; i++)
        ans += dp[n][i] * i;

    cout << fixed << ans;

    return 0;
}
