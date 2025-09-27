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
    int n, x;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int f = -1, l = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] && f == -1) {
            f = i;
        }
        if (a[i]) l = i;
    }

    cout << (l - f < x ? "YES" : "NO") << endl;
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
