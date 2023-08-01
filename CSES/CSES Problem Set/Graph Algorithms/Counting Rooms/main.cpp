// ﷽
// 12 جُمادى الآخرة 1444
// Jan 04, 2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
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

    string b[n];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    function<void(int, int)> dfs = [&](int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= m || b[i][j] != '.')
            return;
        b[i][j] = 'x';
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (b[i][j] == '.')
                ans++, dfs(i, j);
        }
    }

    cout << ans << endl;

    return 0;
}
