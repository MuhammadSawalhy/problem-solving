#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int ans = accumulate(a.begin(), a.end(), 0ll);
    int total = -1;
    for (int i = 0; i < m; i++) total &= b[i];
    for (int i = 0; i < n; i++) {
        a[i] &= ~total;
    }

    // for each a[i], we need to calculate the min value achievable using x operations <= m
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e18));

    // for (int i = 0; i < n; i++) {
    //     dp[i][0] = a[i];
    //     for (int j = 1; j <= m; j++) {
    //         for (int k = 0; k < m; k++) {
    //             dp[i][j] = min(dp[i][j], dp[i][j - 1] & b[k]);
    //         }
    //     }
    //     assert(dp[i][m] == 0);
    // }
    
    vector<int> masks(1 << m, -1);

    for (int mask = 0; mask < 1 << m; mask++) {
        for (int j = 0; j < m; j++) {
            if (mask >> j & 1) masks[mask] &= b[j];
        }
        int j = __builtin_popcount(mask);
        for (int i = 0; i < n; i++) {
            dp[i][j] = min(dp[i][j], a[i] & masks[mask]);
        }
    }

    auto getops = [&](int i, int mx) -> int {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] < mx) return j;
        }
        return k;
    };

    debug(a);
    debug(b);
    debug(ans);

    int i = 30;
    while (i >= 0) {
        debug(i);
        int kk = 0;
        int ops = 0;
        for (int j = 0; j < n; j++) {
            ops += getops(j, 1 << i);
        }
        if (ops > k) {
            i++;
            break;
        }
        i--;
    }

    debug(i);

    if (i == -1) {
        for (int i = 0; i < n; i++) {
            ans += dp[i][m] - a[i];
        }
    } else {
        assert(i > 0);
        vector<int> delta(n);
        for (int j = 0; j < n; j++) {
            int ops = getops(j, 1 << i);
            ans += dp[j][ops] - a[j];
            k -= ops;
            if (ops + 1 <= m)
                delta[j] = dp[j][ops + 1] - dp[j][ops];
        }
        assert(k >= 0 && k < n);
        sort(delta.begin(), delta.end());
        for (int i = 0; i < k; i++) {
            ans += delta[i];
        }
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) debug(t), solve();

    return 0;
}
