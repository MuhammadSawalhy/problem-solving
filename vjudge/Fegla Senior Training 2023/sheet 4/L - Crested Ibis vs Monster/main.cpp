// ﷽
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int h, n;
    cin >> h >> n;

    const int N = 1001, H = 30003;
    int dp[H];
    memset(dp, 0x3f, sizeof dp);

    dp[0] = 0;
    for (int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        for (int j = 0; j < H; j++) {
            if (j - a >= 0)
                dp[j] = min(dp[j], dp[j - a] + b);
        }
    }

    int ans = 1e9;
    for (int i = h; i < H; i++)
        ans = min(ans, dp[i]);
    cout << ans << endl;

    return 0;
}

