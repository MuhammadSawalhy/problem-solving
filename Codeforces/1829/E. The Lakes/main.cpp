// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int n, m;
int lake[1001][1001];

int go(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || lake[i][j] == 0) return 0;
    int ans = lake[i][j];
    lake[i][j] = 0;
    ans += go(i + 1, j);
    ans += go(i - 1, j);
    ans += go(i, j - 1);
    ans += go(i, j + 1);
    return ans;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> lake[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (lake[i][j] != 0)
                ans = max(ans, go(i, j));
    }
    cout << ans << endl;
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
