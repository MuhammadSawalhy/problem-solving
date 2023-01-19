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

    int n, a, b;
    cin >> n >> a >> b;

    long double dp[n + 1][6 * n + 1];
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 6 * n; j++) {
            for (int k = j + 1; k <= j + 6 && k <= 6 * n; k++)
                dp[i + 1][k] += dp[i][j] / 6;
        }
    }

    long double ans = 0;
    for (int i = a; i <= b; i++)
        ans += dp[n][i];

    cout << fixed << ans;

    return 0;
}
