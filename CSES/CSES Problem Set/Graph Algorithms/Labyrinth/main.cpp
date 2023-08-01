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

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> qu;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 'A')
                qu.push({i, j});

    auto go = [&](int i, int j, int ii, int jj) {
        if (ii < 0 || jj < 0 || ii >= n || jj >= m) return;
        if (grid[ii][jj] == '#' || parent[ii][jj].first != -1 || grid[ii][jj] == 'A') return;
        qu.push({ii, jj});
        parent[ii][jj] = {i, j};
    };

    while (qu.size()) {
        auto [i, j] = qu.front();
        qu.pop();
        if (grid[i][j] == 'B') {
            cout << "YES" << endl;
            string path;
            pair<int, int> current = {i, j};
            while (parent[current.first][current.second].first != -1) {
                auto p = parent[current.first][current.second];
                char dir;
                if (current.first == p.first + 1) dir = 'D';
                if (current.first == p.first - 1) dir = 'U';
                if (current.second == p.second + 1) dir = 'R';
                if (current.second == p.second - 1) dir = 'L';
                path += dir;
                current = p;
            }
            reverse(all(path));
            cout << path.length() << endl;
            cout << path << endl;
            return 0;
        }
        go(i, j, i - 1, j);
        go(i, j, i + 1, j);
        go(i, j, i, j - 1);
        go(i, j, i, j + 1);
    }

    cout << "NO" << endl;

    return 0;
}
