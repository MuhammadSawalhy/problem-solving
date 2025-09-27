#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int i = 1, j = 2;
    int y1 = (i * a[j] - j * a[i]);
    int y2 = ((i - j) * (n + 1));
    int y = y1 / y2;
    if (y1 % y2) {
        cout << "NO\n";
        return;
    }

    int x1 = (1LL * a[i] * (n - j + 1) - 1LL * a[j] * (n - i + 1));
    int x2 = (1LL * (i - j) * (n + 1));
    int x = x1 / x2;
    if (x1 % x2) {
        cout << "NO\n";
        return;
    }

    if (x < 0 || y < 0) {
        cout << "NO\n";
        return;
    }


    debug(x, y);
    for (int i = 1; i <= n; i++) {
        if (x * i + y * (n - i + 1) != a[i]) {
            debug(i);
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
