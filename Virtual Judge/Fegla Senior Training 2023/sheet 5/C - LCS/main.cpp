// ﷽
#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

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

    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s[i - 1] == t[j - 1])
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }

    string lcs;
    int i = n, j = m;
    while (j > 0 && i > 0) {
        while (j > 0 && dp[i][j] == dp[i][j - 1]) j--;
        while (i > 0 && dp[i][j] == dp[i - 1][j]) i--;
        if (i == 0 || j == 0) break;
        assert(s[i - 1] == t[j - 1]);
        lcs += s[i - 1];
        i--, j--;
    }

    reverse(all(lcs));
    cout << lcs;

    return 0;
}
