// ﷽
// 10 جُمادى الآخرة 1444
// Jan 02, 2023
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

    string grid[8];
    for (int i = 0; i < 8; i++)
        cin >> grid[i];

    int col[8];
    iota(col, col + 8, 0);

    bool diag[15];
    bool rdiag[15];
    int ans = 0;
    do {
        bool ok = true;
        for (int i = 0; i < 8; i++)
            if (grid[i][col[i]] == '*') ok = false;
        for (int i = 0; i < 15; i++)
            diag[i] = rdiag[i] = false;
        for (int i = 0; i < 8; i++) {
            if (diag[i + col[i]] || rdiag[i + 7 - col[i]])
                ok = false;
            diag[i + col[i]] = rdiag[i + 7 - col[i]] = true;
        }
        ans += ok;
    } while (next_permutation(col, col + 8));

    cout << ans;

    return 0;
}
