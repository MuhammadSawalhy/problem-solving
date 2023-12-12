// ﷽
// https://codeforces.com/contest/321/problem/E

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int inf = 1e9;
const int N = 4004, K = 808;
int dp[K][N];
int a[N][N];
int b[N][N];

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j], a[i][j] += a[i][j - 1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            b[i][j] = a[i][i] - a[i][j - 1] + b[i - 1][j];
        }
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i][j] = inf;
        }
    }

    auto get_value = [&](int i, int j, int r) {
        return min(inf, dp[i - 1][r] + b[j][r + 1]);
    };

    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        int r = 0;
        for (int j = i; j <= n; j++) {
            while (r + 1 < j && get_value(i, j, r + 1) <= get_value(i, j, r)) {
                r++;
            }
            for (int x = r; x < j && x < r + 100; x++) {
                minit(dp[i][j], get_value(i, j, x));
            }
        }
    }

    cout << dp[k][n] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
