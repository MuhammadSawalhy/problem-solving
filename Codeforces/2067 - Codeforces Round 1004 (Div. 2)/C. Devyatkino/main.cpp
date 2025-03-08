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
    int n;
    cin >> n;

    debug(n);
    int p = 1, ones = 1;
    int ans = 7;

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 7; j++) {
            for (int k = 0; k < 7; k++) {
                int nn = n + ones * 9 * j + (ones / 10) * 9 * k;
                if (nn / p % 10 == 7) {
                    ans = min(ans, j + k);
                }
            }
        }

        p *= 10;
        ones += p;
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("----------------------");
        solve();
    }

    return 0;
}
