// ﷽
#include <bits/stdc++.h>

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

using namespace std;

const int N = 5001;
int dp[N][N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    dp[n][m] = 0;

    for (int i = 0; i < n; i++) {
        dp[i][m] = n - i;
    }

    for (int j = 0; j < m; j++) {
        dp[n][j] = m - j;
    }

    for (int i = n - 1; ~i; i--) {
        for (int j = m - 1; ~j; j--) {
            dp[i][j] = min({
                    dp[i][j + 1] + 1,                // delete t[j] or insert t[j] in s (same effect)
                    dp[i + 1][j] + 1,                // delete s[i] or insert s[i] in t (same effect)
                    dp[i + 1][j + 1] + (s[i] != t[j])// replace one to match the other if not equal
            });
        }
    }

    debug_itr(dp, n + 1, m + 1);

    cout << dp[0][0];

    return 0;
}
