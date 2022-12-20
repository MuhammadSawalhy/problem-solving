// Date: 12-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int m;
    cin >> m;
    string grid[2];
    cin >> grid[0] >> grid[1];
    int b = 0;
    for (auto c : grid[0]) b += c == 'B';
    for (auto c : grid[1]) b += c == 'B';
    
    auto dfs = [&](int i, int j) {
        if (grid[i][j] != 'B')
            return false;
        debug(i, j);
        int cnt = 1;
        bool vis[2][m];
        memset(vis, 0, sizeof vis);

        while (true) {
            vis[i][j] = true;
            int k = (i + 1) % 2;
            bool ok1 = j < m && grid[i][j + 1] == 'B' && !vis[i][j + 1];
            bool ok2 = grid[k][j] == 'B' && !vis[k][j];
            if (ok1 && ok2) {
                i = k;
                cnt += 1;
            }
            else if (ok1) {
                j++;
                cnt += 1;
            }
            else if (ok2) {
                i = k;
                cnt += 1;
            } else {
                break;
            }
        }
        
        return cnt == b;
    };

    bool ok = false;

    for (int i = 0; i < m; i++) {
        if (grid[0][i] == 'B' || grid[1][i] == 'B') {
            ok = dfs(0, i) || dfs(1, i);
            break;
        }
    }

    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
