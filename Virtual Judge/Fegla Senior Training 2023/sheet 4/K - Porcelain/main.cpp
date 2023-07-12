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
const int N = 101, M = 10001;
int n, m, dp[N][M], sz[N], mx[N][N];
vector<int> rows[N];


int solve(int i, int taken) {
    if (taken > m) return -1e9;
    if (i >= n) return 0;

    int &r = dp[i][taken];
    if (~r) return r;

    for (int l = 0; l <= sz[i]; l++) {
        r = max(r, solve(i + 1, taken + l) + mx[i][l]);
    }

    return r;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(dp, -1, sizeof dp);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> sz[i];
        for (int j = 0, a; j < sz[i]; j++)
            cin >> a, rows[i].push_back(a);
        for (int j = 0; j < sz[i]; j++)
            rows[i].push_back(rows[i][j]);
        for (int j = 1; j < 2 * sz[i]; j++)
            rows[i][j] += rows[i][j - 1];
        for (int l = 0; l <= sz[i]; l++)
            for (int j = sz[i] - l; j <= sz[i]; j++) {
                mx[i][l] = max(mx[i][l], rows[i][j + l - 1] - (j > 0 ? rows[i][j - 1] : 0));
            }
    }

    cout << solve(0, 0);

    return 0;
}
