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

void solve() {
    int n, m;
    cin >> n >> m;

    int a = 0, b = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a += x;
    }
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        b += x;
    }

    if (a == b) {
        cout << "Draw\n";
    } else if (a > b) {
        cout << "Tsondu\n";
    } else {
        cout << "Tenzing\n";
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
