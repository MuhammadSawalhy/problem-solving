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
    int a[n];
    int b[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    bool a_ex[n + 1][2];
    memset(a_ex, 0, sizeof a_ex);

    bool b_ex[n + 1][2];
    memset(b_ex, 0, sizeof b_ex);

    auto check = [&](int i) {
        return a[i] == b[i] || a_ex[b[i]][i & 1] || b_ex[a[i]][i & 1] || b_ex[b[i]][i & 1 ^ 1] || a_ex[a[i]][i & 1 ^ 1];
    };

    debug_itr(a, n);
    debug_itr(b, n);
    for (int i = n - 1; i >= 0; i--) {
        debug(i);
        int ca = a[i];
        int cb = b[i];

        if (check(i)) {
            cout << i + 1 << endl;
            return;
        }

        // delete at i
        if (i > 0) {
            a[i] = a[i - 1];
            b[i] = b[i - 1];
            if (check(i)) {
                cout << i << endl;
                return;
            }
        }

        a_ex[ca][i & 1] = true;
        b_ex[cb][i & 1] = true;
    }

    cout << 0 << endl;
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
