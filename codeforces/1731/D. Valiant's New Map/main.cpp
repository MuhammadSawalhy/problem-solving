// Date: 27-12-2022
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    vector<vector<long long>> ps(n + 1, vector<long long>(m + 1));

    auto isvalid = [&](int l) {
        if (l > n || l > m) return false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ps[i + 1][j + 1] = min(l, grid[i][j]);
            }
        }

        for (int i = 0; i <= n; i++) {
            ps[i][0] = 0;
        }

        for (int i = 0; i <= m; i++) {
            ps[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] += ps[i][j - 1];
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] += ps[i - 1][j];
            }
        }

        for (int i = l - 1; i < n; i++) {
            for (int j = l - 1; j < m; j++) {
                // query minimum in a sub matrix
                long long q;
                q = ps[i + 1][j + 1];
                q -= ps[i + 1 - l][j + 1];
                q -= ps[i + 1][j + 1 - l];
                q += ps[i + 1 - l][j + 1 - l];
                if (q == (long long)l * l * l) {
                    return true;
                }
            }
        }

        return false;
    };

    long long s = 1, e = 1e6 + 1;
    while (e - s > 1) {
        long long mid = (s + e) / 2;
        if (isvalid(mid)) {
            s = mid;
        } else {
            e = mid;
        }
    }

    cout << s << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
