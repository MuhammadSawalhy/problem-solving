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

    int n, m, k;
    cin >> n >> m >> k;

    string maze[n];
    for (int i = 0; i < n; i++)
        cin >> maze[i];

    queue<pair<int, int>> qu;
    const int d[][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    auto valid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && maze[i][j] != '.' && maze[i][j] != '#';
    };

    int dots = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                maze[i][j] = 'X';
                dots++;
            }
        }

    k = dots - k;
    if (k == 0) { goto end; }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maze[i][j] == 'X') {
                k--;
                maze[i][j] = '.';
                qu.push({i, j});
                goto bfs;
            }
bfs:;
    while (qu.size()) {
        if (k == 0) break;
        auto [i, j] = qu.front();
        qu.pop();

        for (auto [di, dj]: d) {
            if (!valid(i + di, j + dj)) continue;
            k--;
            maze[i + di][j + dj] = '.';
            qu.push({i + di, j + dj});
            if (k == 0) break;
        }
    }

end:;
    for (int i = 0; i < n; i++)
        cout << maze[i] << endl;

    return 0;
}
