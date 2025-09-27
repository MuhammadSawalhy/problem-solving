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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int b = 0; b < 61; b++) {
        for (int i = 0; i < n && (k >= (1LL << b)); i++) {
            if (a[i] >> b & 1 ^ 1) {
                k -= 1LL << b;
                a[i] ^= 1LL << b;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += __popcount(a[i]);
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
