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

const int M = 11, N = 1001;
int n, m, c0, d0, dp[M][N];
struct {
    int a, b, c, d;
} stuf[M];

int solve(int i, int j) {
    if (j <= 0) return 0;
    if (i >= m) return j / c0 * d0;
    int &r = dp[i][j];
    if (~r) return r;

    for (int cnt = 0; cnt <= stuf[i].a / stuf[i].b; cnt++) {
        if (cnt * stuf[i].c > j) break;
        r = max(r, solve(i + 1, j - cnt * stuf[i].c) + cnt * stuf[i].d);
    }

    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m >> c0 >> d0;

    for (int i = 0; i < m; i++) {
        cin >> stuf[i].a >> stuf[i].b >> stuf[i].c >> stuf[i].d;
    }

    memset(dp, -1, sizeof dp);
    cout << solve(0, n);

    return 0;
}
