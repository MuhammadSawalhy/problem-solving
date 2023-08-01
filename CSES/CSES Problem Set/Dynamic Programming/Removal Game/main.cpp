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

const int N = 5002;
ll dp[N][N], s[N], a[N];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);


    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + i <= n + 1; j++) {
            dp[j][i + j] = max(a[j] + s[i + j - 1] - s[j] - dp[j + 1][i + j], a[j + i - 1] + (s[j + i - 2] - s[j - 1] - dp[j][j + i - 1]));
        }
    }
    
    cout << dp[1][n + 1] << '\n';

    return 0;
}
