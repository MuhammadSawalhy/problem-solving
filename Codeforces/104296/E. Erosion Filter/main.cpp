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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int a[n + 1];

    long double dp[n + 1], dp2[n + 2];
    dp[0] = dp2[n + 1] = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = dp[i - 1] / 2 + a[i];
    }

    for (int i = n; i > 0; i--) {
        dp2[i] = dp2[i + 1] / 2 + a[i];
    }


    cout << setprecision(6) << fixed;

    for (int i = 1; i <= n; i++) {
        cout << dp[i] + dp2[i] - a[i] << ' ';
    }

    return 0;
}
