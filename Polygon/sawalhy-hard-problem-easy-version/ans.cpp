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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

constexpr int MOD = 1000000007;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ymin, ymax, s, e, w;
    cin >> ymin >> ymax >> s >> e >> w;

    if (ymin > ymax || max(s, e) > ymax || min(s, e) < ymin) {
        cout << 0 << endl;
        return 0;
    }

    ymax -= ymin;
    s -= ymin;
    e -= ymin;

    int dp[2][ymax + 1];
    memset(dp, 0, sizeof dp);

    int DP = 0;
    dp[DP][s] = 1;

    for (int i = 1; i <= w; i++) {
        DP ^= 1;
        for (int y = 0; y <= ymax; y++) dp[DP][y] = 0;
        for (int y = 0; y <= ymax; y++) {
            if (y - 1 >= 0)
                dp[DP][y] = (dp[DP][y] + dp[DP ^ 1][y - 1]) % MOD;
            if (y + 1 <= ymax)
                dp[DP][y] = (dp[DP][y] + dp[DP ^ 1][y + 1]) % MOD;
        }
    }

    cout << dp[DP][e] << endl;

    return 0;
}
