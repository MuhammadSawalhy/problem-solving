// Date: 01-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    ll l[n + 1], r[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    int k;
    cin >> k;

    //             ///// MY THINKING PROCESS \\\\\\\
    //
    // take the i-th integer from the i-th range
    // how many integer in this range starts with one -> probability of good integers
    // we need to get the product of k+ probabilities * product of the complement of the rest
    // and sum these results and print at the end
    //
    // violent brute forcing:
    //  permutate and loop over them
    //
    // what about dp[i][k]? but we will get more than a result
    // let's get the sum of them
    // and at the end prob = sum(dp[n][ceil(n*k/100.0)]...dp[n][n])
    // dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i])

    long double dp[n + 1][n + 1];
    long double p[n + 1];
    memset(dp, 0, sizeof dp);

    dp[0][0] = 1;
    
    // got 5 wrong answers due to this function
    auto calc = [](ll l, ll r) {
        debug(l,r);
        long long cnt = 0;
        long long m = 1;
        long long x = l;

        while (x >= 10)
            x /= 10;

        if (x == 1) {
            while (x <= l)
                x *= 10;
            x /= 10;
            cnt = min(x * 2 - 1, r) - l + 1;
        }

        while (m <= l)
            m *= 10;

        while (m <= r) { // 1e18
            cnt += min(r, m * 2 - 1) - m + 1;
            if (m == 1e18) break;
            m *= 10;
        }

        debug(cnt);
        debug();

        return (long double) cnt / (r - l + 1);
    };

    for (int i = 1; i <= n; i++) {
        p[i] = calc(l[i], r[i]);
        assert(p[i] <= 1);
        dp[i][0] = dp[i - 1][0] * (1 - p[i]);
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] * (1.0 - p[i]) + dp[i - 1][j - 1] * p[i];
        }
    }

    int s = (n * k + 99) / 100; // ceiling

    long double prob = 0;
    for (int i = s; i <= n; i++)
        prob += dp[n][i];
    cout << fixed << setprecision(15) << prob << endl;

    return 0;
}
