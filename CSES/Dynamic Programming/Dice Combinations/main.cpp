// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int dp[n + 10];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i + j] += dp[i];
            dp[i + j] %= (int)1e9 + 7;
        }
    }

    cout << dp[n];

    return 0;
}
