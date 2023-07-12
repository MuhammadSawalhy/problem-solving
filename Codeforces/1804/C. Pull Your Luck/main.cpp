// ﷽
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
    int n, x, p;
    cin >> n >> x >> p;

    // (f) * (f + 1) / 2 + x == 0 (mod n)
    // m * m + m = ?

    debug(n, x, p);
    for (ll i = 1; i <= min(3 * n, p); i++) {
        if (((i) * (i + 1) / 2 + x) % n == 0) {
            return cout << "Yes" << endl, void();
        }
    }

    cout << "No" << endl;
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
