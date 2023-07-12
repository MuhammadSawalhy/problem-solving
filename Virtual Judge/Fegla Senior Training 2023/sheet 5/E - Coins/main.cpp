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

    int n;
    cin >> n;

    double p[n + 1], dp[n + 1][n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;

    for (int j = 0; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
        }
    }

    double ans = 0;
    for (int j = n / 2 + 1; j <= n; j++)
        ans += dp[n][j];
    
    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
