// ﷽
#include <bits/stdc++.h>
#include <sstream>

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

int n, m;

void solve() {
    cin.ignore();
    string row, cell;
    string table[n][m];
    for (int i = 0; i < n; i++) {
        getline(cin, row);
        istringstream is(row);
        int j = 0;
        while (getline(is, cell, ',')) {
            table[i][j++] = cell;
        }
    }

    debug_itr(&table[0][0], &table[0][0] + n * m, m);

    for (int j = 0; j < m; j++) {
        for (int k = j + 1; k < m; k++) {
            for (int i = 0; i < n; i++) {
                for (int i = 0; i < n; i++) {
                    map<pair<int, int>, int> cols;
                    if (table[i][j] == table[i][k]) {
                        // mark this row and these two cols
                        if (cols.count({j, k})) {
                            cout << "NO" << endl;
                            cout << cols[{i, j}] + 1<< " " << i + 1 << endl;
                            cout << j + 1<< " " << k + 1 << endl;
                            return;
                        }
                        cols[{j, k}] = i;
                    }
                }
            }
        }
    }

    cout << "YES" << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> m) {
        solve();
    }

    return 0;
}
