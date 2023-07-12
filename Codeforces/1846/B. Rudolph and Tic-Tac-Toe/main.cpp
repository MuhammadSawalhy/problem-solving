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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    char grid[3][3];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> grid[i][j];

    auto check = [&](char c) -> bool {
        bool ok = true;
        for (int i = 0; i < 3; i++)
            ok &= grid[i][i] == c;
        if (ok) return true;
        ok = true;
        for (int i = 0; i < 3; i++)
            ok &= grid[i][2 - i] == c;
        if (ok) return true;

        for (int i = 0; i < 3; i++) {
            ok = true;
            for (int j = 0; j < 3; j++) {
                ok &= grid[i][j] == c;
            }
            if (ok) return true;
        }

        for (int i = 0; i < 3; i++) {
            ok = true;
            for (int j = 0; j < 3; j++) {
                ok &= grid[j][i] == c;
            }
            if (ok) return true;
        }

        return false;
    };

    for (char c: vector<char>{'+', 'X', 'O'}) {
        if (check(c)) {
            cout << c << '\n';
            return;
        }
    }
    cout << "DRAW\n";
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
