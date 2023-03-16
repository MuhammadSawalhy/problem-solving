// ﷽
#include <bits/stdc++.h>

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string ice[n];
    for (int i = 0; i < n; i++)
        cin >> ice[i];

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;

    queue<pair<int, int>> qu;
    const int d[][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

    auto valid = [&](int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && ice[i][j] == '.';
    };

    ice[r1][c1] = '.';

    int cnt = 0;
    for (auto [di, dj]: d) {
        cnt += valid(r2 + di, c2 + dj);
    }

    if (ice[r2][c2] == '.' && cnt < 2 && !(r1 == r2 && c1 == c2 && cnt == 1)) {
        cout << "NO\n";
        return 0;
    }

    ice[r2][c2] = '.';

    for (auto [di, dj]: d) {
        if (!valid(r1 + di, c1 + dj)) continue;
        ice[r1 + di][c1 + dj] = 'X';
        qu.push({r1 + di, c1 + dj});
    }

    while (qu.size()) {
        auto [i, j] = qu.front();
        qu.pop();

        if (i == r2 && j == c2) {
            cout << "YES\n";
            return 0;
        }

        for (auto [di, dj]: d) {
            if (!valid(i + di, j + dj)) continue;
            ice[i + di][j + dj] = 'X';
            qu.push({i + di, j + dj});
        }
    }

    cout << "NO\n";

    return 0;
}
