// ﷽
// https://codeforces.com/contest/1869/problem/C
// Codeforces -> Codeforces Round 896 (Div. 2) -> C. Fill in the Matrix

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

void solve() {
    int n, m;
    cin >> n >> m;

    if (m == 1) {
        cout << 0 << '\n';
        for (int i = 0; i < n; i++)
            cout << 0 << '\n';
        return;
    }

    vector<int> row(m);
    iota(all(row), 0);

    rotate(row.begin(), row.end() - 1, row.end());
    int mex = min(n + 1, m);
    cout << mex << '\n';

    for (int i = 1; i < min(m, n + 1); i++) {
        if (i == m / 2 + 1 && m % 2 == 1)
            swap(row[m / 2], row[m / 2 - 1]);
        for (int j = 0; j < m; j++)
            cout << row[j] << " \n"[j == m - 1];
        rotate(row.begin() + i, row.end() - 1, row.end());
    }

    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < m; j++)
            cout << row[j] << " \n"[j == m - 1];
    }
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
