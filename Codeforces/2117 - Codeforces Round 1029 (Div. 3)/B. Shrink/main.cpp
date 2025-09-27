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
    int l = 0, r = n - 1;
    for (int i = 0; i < n;i++) {
        if (i & 1) {
            a[r--] = i + 1;
        } else {
            a[l++] = i + 1;
        }
    }

    for (int i = 0; i < n;i ++) cout << a[i] << " \n"[i == n - 1];
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
