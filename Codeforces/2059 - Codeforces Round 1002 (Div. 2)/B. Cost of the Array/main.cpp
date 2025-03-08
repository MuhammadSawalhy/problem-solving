#include <bits/stdc++.h>
using namespace std;
#define int long long

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n;i++) cin >> a[i];

    if (n == k) {
        vector<int> b;
        for (int i = 1; i < n; i += 2) b.push_back(a[i]);
        b.push_back(0);

        int i = 1;
        while (i <= n && b[i - 1] == i) i++;
        cout << i << endl;
        return;
    }

    int m = n - k + 2;

    int ones = 0;
    for (int i = 1; i < m; i++) {
        ones += a[i] == 1;
    }

    if (ones == m - 1) {
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
