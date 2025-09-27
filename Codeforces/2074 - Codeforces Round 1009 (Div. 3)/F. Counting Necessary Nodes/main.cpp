#include <bits/stdc++.h>
#include <system_error>
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
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = 1LL * (r1 - l1) * (r2 - l2);

    for (int p = 2; p < 1e7; p *= 2) {
        l1 = (l1 + p - 1) / p * p;
        l2 = (l2 + p - 1) / p * p;
        r1 = r1 / p * p;
        r2 = r2 / p * p;
        if (l1 > r1 || l2 > r2) break;

        ans -= 1LL * (r1 - l1) * (r2 - l2) / (p / 2) / (p / 2);
        ans += 1LL * (r1 - l1) * (r2 - l2) / p / p;
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("_----------------", t);
        solve();
    }

    return 0;
}
