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

bool vis[7][7];
string path, curr(48, ' ');
int ans;

bool valid(int i, int j) {
    return !(i < 0 || j < 0 || i >= 7 || j >= 7 || vis[i][j]);
}

bool check(int i, int j, int step) {
    if (step == 0) return true;
    char d = curr[step - 1];
    if (d == 'L' && !valid(i, j - 1) && valid(i + 1, j) && valid(i - 1, j))
        return false;
    if (d == 'R' && !valid(i, j + 1) && valid(i + 1, j) && valid(i - 1, j))
        return false;
    if (d == 'D' && !valid(i + 1, j) && valid(i, j + 1) && valid(i, j - 1))
        return false;
    if (d == 'U' && !valid(i - 1, j) && valid(i, j + 1) && valid(i, j - 1))
        return false;
    return true;
}

void dfs(int i, int j, int step) {
    if (!valid(i, j)) return;
    if (step > 1 && path[step - 1] != '?' && path[step - 1] != curr[step - 1]) return;
    if (!check(i, j, step)) return;
    if (step == 48 || i == 6 && j == 0) {
        ans += i == 6 && j == 0 && step == 48;
        return;
    }

    vis[i][j] = true;
    curr[step] = 'D';
    dfs(i + 1, j, step + 1);
    curr[step] = 'U';
    dfs(i - 1, j, step + 1);
    curr[step] = 'R';
    dfs(i, j + 1, step + 1);
    curr[step] = 'L';
    dfs(i, j - 1, step + 1);
    vis[i][j] = false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> path;

    dfs(0, 0, 0);

    cout << ans;

    return 0;
}
