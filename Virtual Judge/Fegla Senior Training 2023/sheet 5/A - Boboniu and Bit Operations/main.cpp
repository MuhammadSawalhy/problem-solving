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

const int N = 202;
int n, m, a[N], b[N];
bool dp[N][1 << 10];

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int mask = 0; mask < 1 << 9; mask++) {
                dp[i + 1][mask | (a[i] & b[j])] |= dp[i][mask];
            }
        }
    }

    for (int j = 0; j < 1 << 9; j++) {
        if (dp[n][j]) {
            cout << j << endl;
            break;
        }
    }

    return 0;
}
