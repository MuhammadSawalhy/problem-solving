// ﷽
// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int a, b;
ll dp[19][11][2][2][2];

ll p[19];

int digit(ll a, int i) {
    return a / p[i] % 10;
}

ll solve(int i, int last, bool A, bool B, bool trailing_zero) {
    debug(i, last, A, B);
    if (i == -1) return 1;
    ll &ans = dp[i][last][A][B][trailing_zero];
    if (~ans) return ans;

    ans = 0;

    for (int d = (A ? digit(a, i) : 0); d <= (B ? digit(b, i) : 9); d++) {
        if (d == last && d != 0 || d == last && d == 0 && !trailing_zero) continue;
        ans += solve(i - 1, d, A & (d == digit(a, i)), B & (d == digit(b, i)), trailing_zero & (d == 0));
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    memset(dp, -1, sizeof dp);

    p[0] = 1;
    for (int i = 1; i < 19; i++)
        p[i] = p[i - 1] * 10;

    cin >> a >> b;

    cout << solve(18, 10, true, true, true);

    return 0;
}
