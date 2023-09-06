// ﷽
// https://codeforces.com/contest/1864/problem/A
// Codeforces -> Harbour.Space Scholarship Contest 2023-2024 (Div. 1 + Div. 2) -> A. Increasing and Decreasing

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
    int x, y, n;
    cin >> x >> y >> n;

    if (x + (n - 1) * (n) / 2 > y) {
        cout << -1 << endl;
        return;
    }

    int a[n];
    int cur = y;
    for (int i = n - 1, j = 1; i >= 0; i--, j++) {
        a[i] = cur;
        cur -= j;
    }
    cout << x << ' ';
    for (int i = 1; i < n; i++) cout << a[i] << ' ';
    cout << '\n';
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
