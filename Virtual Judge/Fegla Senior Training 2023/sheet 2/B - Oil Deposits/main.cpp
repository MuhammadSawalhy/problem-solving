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

const int M = 100;
int m, n;
string world[M];
char hole = '@';

int dfs(int i, int j) {
    if (i >= m || i < 0 || j >= n || j < 0 || world[i][j] != hole) return 0;
    world[i][j] = hole + 1;

    int cnt = 1;
    
    for (int di = -1; di <= 1; di++)
        for (int dj = -1; dj <= 1; dj++)
            cnt += dfs(i + di, j + dj);

    return cnt;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> m >> n, m) {
        for (int i = 0; i < m; i++) {
            cin >> world[i];
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += !!dfs(i, j);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
