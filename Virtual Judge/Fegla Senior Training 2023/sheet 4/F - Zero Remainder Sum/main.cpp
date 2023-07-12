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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 77;
int dp[N][N][N];// dp for each row
int cur[N];
int row[N][N];// max sum so far with a remainder x
int mat[N][N];
int n, m, k;

void solve_row(int i) {
    memset(dp, 0xc0, sizeof dp);
    memset(cur, 0xc0, sizeof cur);
    dp[0][0][0] = 0;
    cur[0] = 0;
    for (int j = 1; j <= m; j++) {
        for (int l = 0; l <= min(j, m / 2); l++) {
            for (int mod = 0; mod < k; mod++) {
                dp[j][l][mod] = max(dp[j][l][mod], dp[j - 1][l][mod]);
                cur[mod] = max(cur[mod], dp[j][l][mod]);

                if (l > 0) {
                    int MOD = (mod + mat[i][j]) % k;
                    dp[j][l][MOD] = max(dp[j][l][MOD],
                                        dp[j - 1][l - 1][mod] + mat[i][j]);
                    cur[MOD] = max(cur[MOD], dp[j][l][MOD]);
                }
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }

    memset(row, 0xc0, sizeof row);
    row[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        solve_row(i);
        for (int r = 0; r < k; r++) {
            for (int w = 0; w < k; w++)
                row[i][(r + w) % k] = max(row[i][(r + w) % k], row[i - 1][r] + cur[w]);
        }
    }

    cout << row[n][0] << '\n';

    return 0;
}
