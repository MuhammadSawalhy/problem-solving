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
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int ones = 0;
    vector<int> ind;
    int n;

    cin >> n;
    vector<bool> a(n + 1);
    int dp[2][n + 2][n * (n - 1) / 2 + 2];

    for (int i = 1, x; i <= n; i++) {
        cin >> x, ones += x, a[i] = x;
        if (x) ind.push_back(i);
    }

    const int inf = 1e9;
    int DP = 0;

    for (int j = 0; j <= n; j++)
        for (int k = 0; k <= n * (n - 1) / 2; k++)
            dp[DP][j][k] = inf;

    dp[DP][0][0] = 0;

    for (int i = 0; i < ones; i++) { // prefix len
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= n * (n - 1) / 2; k++)
                dp[DP ^ 1][j][k] = inf;

        for (int last = i; last <= n; last++) {
            for (int k = 0; k <= n * (n - 1) / 2; k++) {
                if (dp[DP][last][k] == inf)
                    continue;
                for (int next = last + 1; next <= n; next++)
                    minit(dp[DP ^ 1][next][k + abs(ind[i] - next)], dp[DP][last][k] + (next - last - 1) * (next - last - 2) / 2);
            }
        }

        DP ^= 1;
    }

    vector<int> ans(n * (n - 1) / 2 + 1, inf);
    for (int k = 0; k <= n * (n - 1) / 2; k++) {
        for (int last = 0; last <= n; last++)
            minit(ans[k], dp[DP][last][k] + (n - last) * (n - last - 1) / 2);
        if (k > 0)
            minit(ans[k], ans[k - 1]);
    }

    for (int k = 0; k <= n * (n - 1) / 2; k++)
        cout << (n - ones) * (n - ones - 1) / 2 - ans[k] << ' ';

    return 0;
}
