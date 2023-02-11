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

map<char, int> dx = {{'U', 0},{'D', 0},{'L', -1},{'R', 1},};
map<char, int> dy = {{'U', 1},{'D', -1},{'L', 0},{'R', 0},};

void solve() {
    int n;
    string dirs;
    cin >> n >> dirs;

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        x += dx[dirs[i]];
        y += dy[dirs[i]];
        if (x == 1 && y == 1) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
