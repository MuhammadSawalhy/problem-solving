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

map<string, pair<int, int>> dirs = {
        {"DR", {1, 1}},
        {"DL", {1, -1}},
        {"UR", {-1, 1}},
        {"UL", {-1, -1}},
};


void solve() {
    int n, m, i, j, x, y;
    string dir;
    cin >> n >> m >> i >> j >> x >> y >> dir;

    map<array<int, 4>, bool> vis;
    int di = dirs[dir].first;
    int dj = dirs[dir].second;
    int ans = 0;

    auto step = [&]() {
        bool done = false;
        if (j + dj < 1) {
            dj *= -1;
            done = true;
        }
        if (j + dj > m) {
            dj *= -1;
            done = true;
        }

        if (i + di < 1) {
            di *= -1;
            i = 1;
            done = true;
        }
        if (i + di > n) {
            di *= -1;
            i = n;
            done = true;
        }

        i += di;
        j += dj;
        ans += done;
    };

    do {
        debug(i, j, di, dj);
        if (i == x && j == y) {
            cout << ans << '\n';
            return;
        }

        if (vis[{i, j, di, dj}]) {
            break;
        }

        vis[{i, j, di, dj}] = true;
    } while (step(), 1);

    cout << "-1\n";
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
