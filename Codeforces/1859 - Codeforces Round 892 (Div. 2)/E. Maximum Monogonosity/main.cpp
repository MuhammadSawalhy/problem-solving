// ﷽
// https://codeforces.com/contest/1859/problem/E
// Codeforces -> Codeforces Round 892 (Div. 2) -> E. Maximum Monogonosity

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

const int N = 3003;
int dp[N][N][5];

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    const ll inf = 1e18;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= 4; l++) {
                dp[i][j][l] = -inf;
            }
        }
    }

    dp[0][0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            // case 1: nothing use previous (no mode activated)
            dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0]);
            // case 2: add to already activated mode
            for (int mode = 1; mode <= 4; mode++) {
                dp[i + 1][j + 1][mode] =
                        max(dp[i + 1][j + 1][mode], dp[i][j][mode]);
            }
            // case 3: start mode from non-mode
            for (int mode = 1; mode <= 4; mode++) {
                int a_sign = mode % 2 * 2 - 1;
                int b_sign = mode / 2 % 2 * 2 - 1;
                dp[i + 1][j + 1][mode] =
                        max(dp[i + 1][j + 1][mode], dp[i][j][0] + a_sign * a[i] + b_sign * b[i]);
            }
            // case 4: end the current active mode
            for (int mode = 1; mode <= 4; mode++) {
                int b_sign = 1 - mode % 2 * 2;
                int a_sign = 1 - mode / 2 % 2 * 2;
                dp[i + 1][j][0] =
                        max(dp[i + 1][j][0], dp[i + 1][j][mode] + a_sign * a[i] + b_sign * b[i]);
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int mode = 0; mode <= 4; mode++)
                debug(i, j, mode, dp[i][j][mode]);
        }
    }

    cout << dp[n][k][0] << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
