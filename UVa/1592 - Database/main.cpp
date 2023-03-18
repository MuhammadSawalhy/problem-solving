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


    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            // start work here
            map<pair<string, string>, int> mp;
            for (int k = 0; k < n; k++) {
                debug(k, i, j);
                if (!mp.count({ table[k][i], table[k][j] })) {
                    mp[{ table[k][i], table[k][j] }] = k;
                } else {
                    int row = mp[{ table[k][i], table[k][j] }];
                    cout << "NO" << endl;
                    cout << row + 1 << " " << k + 1 << endl;
                    cout << i + 1 << " " << j + 1 << endl;
                    return;
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
