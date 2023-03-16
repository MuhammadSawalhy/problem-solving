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

const int M = 50;
int m, n;
string world[M];
char hole;

int dfs(int i, int j) {
    if (i >= m || i < 0 || j >= n || j < 0 || world[i][j] != hole) return 0;
    world[i][j] = '.';

    int cnt = 1;
    cnt += dfs(i + 1, j);
    cnt += dfs(i - 1, j);
    cnt += dfs(i, j + 1);
    cnt += dfs(i, j - 1);

    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 0;
    while (cin >> m >> n, m) {
        cout << "Problem " << ++t << ":\n";
        for (int i = 0; i < m; i++) {
            cin >> world[i];
        }

        vector<pair<int, int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (world[i][j] != '.')
                    hole = world[i][j], ans.emplace_back(-dfs(i, j), hole);
            }
        }

        sort(all(ans));

        for (auto p: ans)
            cout << (char)p.second << " " << -p.first << '\n';
    }

    return 0;
}
