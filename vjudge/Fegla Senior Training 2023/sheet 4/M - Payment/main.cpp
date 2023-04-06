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

    string n;
    cin >> n;

    int dp[n.size() + 1][2];
    dp[0][0] = n[0] - '0';
    dp[0][1] = 9 - (n[0] - '0') + 2;
    n += '0';

    for (int i = 1; i < (int)n.size(); i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + n[i] - '0';
        dp[i][1] = min(dp[i - 1][1] + 9 - (n[i] - '0'), dp[i - 1][0] + 9 - (n[i] - '0') + 2);
    }

    cout << dp[n.size() - 1][0];

    return 0;
}
