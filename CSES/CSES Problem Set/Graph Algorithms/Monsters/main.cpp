// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    string grid[n];
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    queue<tuple<int, int, char>> qu;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'M')
                qu.push({i, j, 'M'});
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'A')
                qu.push({i, j, 'A'});

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    auto valid = [&](int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.';
    };

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    auto printit = [&](int i, int j) {
        // print the answer
        string ans;
        const char dir[3][3] = {
                {' ', 'U', ' '},
                {'L', ' ', 'R'},
                {' ', 'D', ' '},
        };
        while (parent[i][j].first != -1) {
            auto [ii, jj] = parent[i][j];
            ans += dir[i - ii + 1][j - jj + 1];
            i = ii, j = jj;
        }
        reverse(all(ans));
        cout << "YES" << endl;
        cout << ans.size() << endl;
        cout << ans << endl;
    };

    while (qu.size()) {
        auto [i, j, c] = qu.front();
        qu.pop();
        grid[i][j] = c;
        int ii = i, jj = j;
        if (c == 'M') {
            for (int k = 0; k < 4; k++) {
                i = ii + dy[k], j = jj + dx[k];
                if (valid(i, j)) qu.push({i, j, 'M'}), grid[i][j] = 'M';
            }
        } else {
            if (i == n - 1 || i == 0 || j == m - 1 || j == 0) {
                printit(i, j);
                return 0;
            }
            for (int k = 0; k < 4; k++) {
                i = ii + dy[k], j = jj + dx[k];
                if (valid(i, j)) {
                    grid[i][j] = 'A';
                    qu.push({i, j, 'A'});
                    parent[i][j] = {ii, jj};
                }
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}
