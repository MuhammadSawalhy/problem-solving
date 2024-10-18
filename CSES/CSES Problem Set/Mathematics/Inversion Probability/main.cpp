// ﷽
#include <bits/stdc++.h>
#include <cmath>

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    long double ans = 0, dp[101];

    for (int i = 0; i < 101; i++) dp[i] = 0;

    int f[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
        for (int x = 1; x <= f[i]; x++) {
            ans += (long double) 1.0 / f[i] * dp[x];
            dp[x] += (long double) 1.0L * (f[i] - x) * 1e7L / f[i];
        }
    }

    ans *= 1e-1;
    cerr << setprecision(20) << fixed;
    debug(ans);

    if (abs(ans - (int) ans) == 0.5) {
        if ((int) ceil(ans) % 2 == 1) {
            ans = floor(ans);
        } else {
            ans = ceil(ans);
        }
    } else {
        ans = round(ans);
    }

    cout << fixed << ans / 1e6;

    return 0;
}
