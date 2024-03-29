// ﷽
#include <bits/stdc++.h>
 
#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif
 
#define int long long
#define ll long long
#define all(v) v.begin(), v.end()
 
using namespace std;
 
constexpr int N = 1000, M = 1e9 + 7;
string grid[N];
int dp[N][N], n, m;
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> grid[i];
 
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#')
                continue;
            if (i + 1 < n)
            {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= M;
            }
            if (j + 1 < m)
            {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= M;
            }
        }
 
    cout << dp[n - 1][m - 1] << endl;
 
    return 0;
}
