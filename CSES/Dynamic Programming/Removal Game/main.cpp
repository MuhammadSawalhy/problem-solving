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

const int N = 5002;
ll dp[N][N][2][2], a[N];
int n;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    for (int i = 1; i <= n; i++) cin >> a[i];


    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j++)
            dp[i][j][0][0] = dp[i][j + 1]

    return 0;
}
