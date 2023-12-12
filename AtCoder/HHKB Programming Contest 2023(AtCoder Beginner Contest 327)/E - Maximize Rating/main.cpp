// ﷽
// https://atcoder.jp/contests/abc327/tasks/abc327_e

#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int p[n];
    for (int i = 0; i < n; i++) cin >> p[i];

    double dp[n + 1];

    for (int i = 0; i <= n; i++) dp[i] = -1e18;

    dp[0] = 0;

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - i; j >= 1; j--) {
            maxit(dp[j], dp[j - 1] + pow(0.9, j - 1) * p[i]);
        }
    }

    double ans = -1e18;

    double denom = 0;
    for (int i = 1; i <= n; i++) {
        denom += pow(0.9, i - 1);
        maxit(ans, dp[i] / denom - 1200 / sqrt(i));
    }

    cout << fixed << setprecision(16);
    cout << ans << endl;

    return 0;
}
