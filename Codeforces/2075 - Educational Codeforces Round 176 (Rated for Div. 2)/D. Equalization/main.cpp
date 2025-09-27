#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define minit(x, y) (x = min(x, y))

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


int dp[60][60][60];

void solve() {
    int x, y;
    cin >> x >> y;
    debug_bits(x);
    debug_bits(y);

    int ans = 1ll << 61;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if ((x >> i) == (y >> j)) minit(ans, dp[59][i][j]);
        }
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);


    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++)
                dp[k][i][j] = 1ll << 61;
        }
    }

    dp[0][0][0] = 0;

    for (int k = 1; k < 60; k++) {
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                minit(dp[k][i][j], dp[k - 1][i][j]);
            }
        }
        for (int i = 0; i < 60; i++) {
            for (int j = 0; j < 60; j++) {
                if (i + k < 60)
                    minit(dp[k][i + k][j], dp[k - 1][i][j] + (1ll << k));
                if (j + k < 60)
                    minit(dp[k][i][j + k], dp[k - 1][i][j] + (1ll << k));
            }
        }
    }

    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            debug(i, j, dp[59][i][j]);
        }
    }

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
