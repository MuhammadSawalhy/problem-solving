// ﷽
// https://codeforces.com/contest/1955/problem/H

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define int long long
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int fast_p(int a, int b) {
    int res = 1;
    for (; b; a *= a, b >>= 1)
        if (b & 1) res *= a;
    return res;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    char grid[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int min_val = 0;

    debug(n, m, k);

    int values[k][12];

    for (int i = 0; i < k; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        x--, y--;

        int mn = 0, mnn = -1;
        for (int r = 1; r <= 12; r++) {
            int k = 0, dx, dy;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (grid[i][j] == '.') continue;
                    dx = x - i;
                    dy = y - j;
                    if (dx * dx + dy * dy <= r * r) {
                        k++;
                    }
                }
            }

            values[i][r - 1] = fast_p(3, r) - k * p;
            debug(i, r, values[i][r - 1]);
        }
    }

    int dp[k + 1][1 << 12];
    memset(dp, '?', sizeof dp);

    dp[0][0] = 0;

    int mn = 0;
    for (int i = 0; i < k; i++) {
        for (int mask = 0; mask < 1 << 12; mask++) {
            minit(dp[i + 1][mask], dp[i][mask]);
            for (int r = 0; r < 12; r++) {
                if (mask >> r & 1 ^ 1) continue;
                minit(dp[i + 1][mask], dp[i][mask ^ (1 << r)] + values[i][r]);
            }
        }
    }

    for (int mask = 0; mask < 1 << 12; mask++) {
        minit(mn, dp[k][mask]);
    }

    cout << -mn << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
