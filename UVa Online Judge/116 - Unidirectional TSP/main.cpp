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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int m, n;
    int grid[10][100];

    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                cin >> grid[i][j];
        }

        int dp[101][10] = {};
        deque<int> path[101][10];

        for (int i = n - 1; ~i; i--) {
            for (int j = 0; j < m; j++) {
                int mn = min({ dp[i + 1][j], dp[i + 1][(j + 1) % m], dp[i + 1][(j - 1 + m) % m] });
                deque<int> mnpath(n - i - 1, 1e9);
                for (auto k : { j, (j + 1) % m, (j - 1 + m) % m }) {
                    if (dp[i + 1][k] == mn) {
                        if (path[i + 1][k] < mnpath)
                            mnpath = path[i + 1][k];
                    }
                }
                mnpath.push_front(j);
                dp[i][j] = grid[j][i] + mn;
                path[i][j] = mnpath;
            }
        }

        int mn = dp[0][0];
        for (int i = 0; i < m; i++) {
            mn = min(mn, dp[0][i]);
        }

        deque<int> mnpath(n, 1e9);

        for (int i = 0; i < m; i++) {
            if (dp[0][i] == mn) {
                if (path[0][i] < mnpath)
                    mnpath = path[0][i];
            }
        }

        for (int i = 0; i < (int)mnpath.size(); i++)
            cout <<  mnpath[i] + 1 << " \n"[i == mnpath.size() - 1];
        cout << mn << endl;
    }

    return 0;
}
