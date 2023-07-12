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

const int N = 90;
// dp[i][moves][zeros]
int dp[N][N][N * (N - 1) / 2];
int n;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    vector<bool> a(n);
    for (int i = 0, x; i < n; i++)
        cin >> x, a[i] = x;

    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int z = 0; z <= i; z++) {
            for (int m = 0; m <= (i) * (i + 1) / 2; m++) {
                if (a[i]) {
                    for (int j = 0; j <= z; j++) {
                        dp[i + 1][j][m + j] = min(dp[i + 1][j][m + j], dp[i][z][m] - (j) * (z - j));
                    }
                } else {
                    dp[i + 1][z + 1][m] = min(dp[i + 1][z + 1][m], dp[i][z][m] + z);
                }
            }
        }
    }

    int zeros = count(all(a), false);
    vector<int> ans(n * (n - 1) / 2 + 1, 0);

    for (int m = 0; m <= n * (n - 1) / 2; m++)
        for (int z = 0; z <= n; z++) {
            ans[m] = max(ans[m], zeros * (zeros - 1) / 2 - dp[n][z][m]);
        }

    for (int m = 1; m <= n * (n - 1) / 2; m++)
        ans[m] = max(ans[m], ans[m - 1]);

    for (int m = 0; m <= n * (n - 1) / 2; m++)
        cout << ans[m] << ' ';

    return 0;
}
