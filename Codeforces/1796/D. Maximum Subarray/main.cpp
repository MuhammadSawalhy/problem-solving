// ﷽
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string.h>
#include <utility>
#include <vector>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const int N = 200200, K = 22;
const ll INF = 1e17;
int a[N], n, k, x;
ll dp[N][K][3];

ll solve(int i, int j, int state) {
    if (j > k || state > 2) return -INF;
    if (i == n) {
        if (j == k) return 0;
        else return -INF;
    }

    ll &r = dp[i][j][state];
    if (r != -1) return r;

    r = -INF;

    if (state == 0) {
        r = max(r, solve(i + 1, j, 0));
        r = max(r, solve(i + 1, j + 1, 0));
        r = max(r, solve(i, j, 1));
    }

    else if (state == 1) {
        r = max(r, solve(i + 1, j, 1) + a[i] - x);
        r = max(r, solve(i + 1, j + 1, 1) + a[i] + x);
        r = max(r, solve(i, j, 2));
    }

    else if (state == 2) {
        r = max(r, solve(i + 1, j, 2));
        r = max(r, solve(i + 1, j + 1, 2));
    }

    return r;
}

void solve() {
    cin >> n >> k >> x;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= k; j++)
            for (int s = 0; s < 3; s++)
                dp[i][j][s] = -1;

    cout << solve(0, 0, 0) << "\n";
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
