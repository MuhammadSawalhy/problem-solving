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

    string n;
    int k;
    cin >> n >> k;
    long long dp[n.size() + 1][5][2];
    memset(dp, 0, sizeof dp);

    dp[1][1][0] = n[0] - '0' - 1;
    dp[1][1][1] = 1;

    for (int i = 1; i < n.size(); i++) {
        dp[i][0][0] = 1;
        for (int j = 1; j < 4; j++) {
            // 314
            if (n[i] == '0') {
                dp[i + 1][j][0] = dp[i][j][0] + dp[i][j - 1][0] * 9;
                dp[i + 1][j][1] = dp[i][j][1];
            } else {
                dp[i + 1][j][0] = dp[i][j][0] + dp[i][j][1] + dp[i][j - 1][0] * 9 + dp[i][j - 1][1] * (n[i] - '0' - 1);
                dp[i + 1][j][1] = dp[i][j - 1][1];
            }
        }
        debug(i);
        debug_itr(dp[i], k + 1, 2);
    }

    debug_itr(dp[n.size()], k + 1, 2);

    cout << dp[n.size()][k][1] + dp[n.size()][k][0] << endl;

    return 0;
}
