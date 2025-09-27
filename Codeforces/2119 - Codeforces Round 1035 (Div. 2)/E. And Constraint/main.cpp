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
    vector<int> a(n - 1);
    vector<int> b(n);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int on = 0, off = 0;
        if (i < n - 1) on |= a[i];
        if (i > 0) on |= a[i - 1];

        debug(b[i], on);
        bool ok = false;

        for (int j = 0; j < 1000; j++) {
            if (((b[i] + j) & on) == on) {
                ans += j;
                ok = true;
                break;
            }
        }

        if (!ok) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ans << endl;
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
