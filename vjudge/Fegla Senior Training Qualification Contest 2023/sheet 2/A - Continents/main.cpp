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

const int M = 20;
int m, n;
string world[M];
char hole;

int dfs(int i, int j) {
    j = (j + n) % n;
    if (i >= m || i < 0 || world[i][j] != hole) return 0;
    world[i][j] = hole + 1;

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

    while (cin >> m >> n) {
        for (int i = 0; i < m; i++) {
            cin >> world[i];
        }

        int a, b;
        cin >> a >> b;
        hole = world[a][b];
        dfs(a, b);

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }

        debug_itr(world, m, 1);
        cout << ans << endl;
    }

    return 0;
}
