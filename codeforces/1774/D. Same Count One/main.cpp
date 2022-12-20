// Date: 17-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int n, m;
    cin >> n >> m;

    int arr[n][m];

    int ones = 0;

    vector<int> cols[2][m];
    vector<int> arrones(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j], ones += arr[i][j], arrones[i] += arr[i][j];
            cols[arr[i][j]][j].push_back(i);
        }
    }

    if (ones % n != 0) {
        cout << -1 << endl;
        return;
    }

    // no double moves, move directly

    vector<array<int, 3>> ans;

    for (int c = 0; c < m; c++) {
        while (true) {
            int i = -1;
            while (cols[1][c].size() && i == -1) {
                int a = cols[1][c].back();
                cols[1][c].pop_back();
                if (arrones[a] > ones / n) {
                    i = a;
                    break;
                }
            }
            if (i == -1) break;
            int j = -1;
            while (cols[0][c].size() && j == -1) {
                int a = cols[0][c].back();
                cols[0][c].pop_back();
                if (arrones[a] < ones / n) {
                    j = a;
                    break;
                }
            }
            if (j == -1) break;

            ans.push_back({i, j, c});
            arrones[i]--;
            arrones[j]++;
        }
    }

    for (int i = 1; i < n; i++) {
        if (arrones[i] != arrones[i - 1]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans.size() << endl;
    for (auto [x, y, i]: ans) {
        cout << y + 1 << " " << x + 1 << " " << i + 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
