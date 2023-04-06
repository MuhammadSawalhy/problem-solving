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

long long cost[2];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int w[n];
    for (int i = 1; i < n; i++) cin >> w[i];

    int dp[n][2];
    memset(dp, 0x3f, sizeof dp);

    for (int i = 2; i < n - 1; i++) {
    }

    int q;
    cin >> q;
    while (q--) {
        int k, x;
        cin >> k >> x;
        if (n == 2) {
            w[k] = x;
            cout << (w[1]) * 2 << '\n';
        } else if (n == 3) {
            w[k] = x;
            cout << (w[1] + w[n - 1]) * 2 << '\n';
        } else {
            cout << (w[1] + w[n - 1] + min(dp)) << '\n';
        }
    }

    return 0;
}
