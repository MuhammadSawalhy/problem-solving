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

const int N = 3003;
long long dp[N][N];
int x[N], c[N], order[N];
int n;

long long solve(int i, int j) {
    if (i >= n) return 0;
    long long &r = dp[i][j];
    if (~r) return r;

    r = 1e18;
    r = min(r, solve(i + 1, i) + c[order[i]]);
    r = min(r, solve(i + 1, j) + x[order[i]] - x[order[j]]);

    return r;
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n;
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < n; i++)
        cin >> x[i] >> c[i];

    iota(order, order + n, 0);
    sort(order, order + n, [](auto l, auto r) { return x[l] < x[r]; });
    debug_itr(order, n);

    cout << solve(1, 0) + c[order[0]];
    debug_itr(dp, n, n);

    return 0;
}
