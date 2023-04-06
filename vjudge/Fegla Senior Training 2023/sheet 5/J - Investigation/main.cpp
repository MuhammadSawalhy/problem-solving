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

#define ll long long
#define all(v) v.begin(), v.end()

const int K = 10000;
int a, b, k;
int dp[10][90][90][2];

int solve(int i, int j, int r, ll p = 1, int target = 0, bool greater = false) {
    if (p > target) return !greater && (j % k == 0) && (r % k == 0);
    j %= k;
    int &ans = dp[i][j][r][greater];
    if (~ans) return ans;

    ans = 0;

    int cur = target / p % 10;
    for (int d = 0; d < 10; d++) {
        ans += solve(i + 1, j + p * d, r + d, p * 10, target, (greater & (d == cur)) | (d > cur));
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> a >> b >> k;
        if (k >= 90) {
            cout << "Case " << i << ": 0\n";
            continue;
        }
        memset(dp, -1, sizeof dp);
        int B = solve(0, 0, 0, 1, b);
        memset(dp, -1, sizeof dp);
        int A = solve(0, 0, 0, 1, a - 1);
        debug(B, A);
        cout << "Case " << i << ": " << B - A << '\n';
    }

    return 0;
}
