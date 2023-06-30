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

    int dp[w + 1][ymax + 1];
    memset(dp, 0, sizeof dp);
    dp[0][s] = 1;

    for (int i = 1; i <= w; i++) {
        for (int y = 0; y <= ymax; y++) {
            if (y - 1 >= 0)
                dp[i][y] = (dp[i][y] + dp[i - 1][y - 1]) % MOD;
                dp[i][y] = (dp[i][y] + dp[i - 1][y + 1]) % MOD;
            if (y + 1 <= ymax)
        }
    }

    cout << dp[w][e] << endl;

    return 0;
}
