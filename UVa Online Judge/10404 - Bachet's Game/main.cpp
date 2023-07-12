// ﷽
#include <bits/stdc++.h>

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

int n, m;
void solve() {
    int nims[m];
    for (int i = 0; i < m; i++)
        cin >> nims[i];

    bool dp[n + 1][2];
    dp[0][0] = true;
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int p: {0, 1}) {
            for (int j = 0; j < m; j++) {
                if (nims[j] <= i)
                    dp[i][p] |= !dp[i - nims[j]][p ^ 1];
            }
        }
    }

    /* debug_itr(dp, n); */
    cout << (dp[n][0] ? "Stan wins\n" : "Ollie wins\n");
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> m)
        solve();

    return 0;
}
