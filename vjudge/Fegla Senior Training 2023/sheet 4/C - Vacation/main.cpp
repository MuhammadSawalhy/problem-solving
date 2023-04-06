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

const int N = 1e5 + 5;
long long dp[N][3];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    cin >> n;

    int points[3];

    for (int i = 0; i < n; i++) {
        cin >> points[0] >> points[1] >> points[2];
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][k] + points[j]);
            }
        }
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2]));
    
    return 0;
}
