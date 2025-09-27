#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

long long dp[5][1001][8001];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i][4000] = 1;
    }

    for (int c = 1; c <= 4; c++) {
        for (int i = 0; i < n; i++) {
            for (int sum = -4000; sum <= 4000; sum++) {
                dp[c][i + 1][sum + 4000] += dp[c][i][sum + 4000];
                if (sum - a[i] >= -4000 && sum - a[i] <= 4000)
                    dp[c][i + 1][sum + 4000] += dp[c - 1][i][sum - a[i] + 4000];
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int sum;
        cin >> sum;
        cout << dp[4][n][sum + 4000] << '\n';
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
