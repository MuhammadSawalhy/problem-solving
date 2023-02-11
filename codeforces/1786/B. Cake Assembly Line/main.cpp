// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, w, h;
    cin >> n >> w >> h;
    int a[n], b[n];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l = -1e9, r = 1e9;
    for (int i = 0; i < n; i++) {
        int L = b[i] + w - h - a[i], R = b[i] - w + h - a[i];
        if (L > R)
            swap(L, R);
        debug(i, L, R);
        l = max(l, L);
        r = min(r, R);
    }

    debug(l, r);
    if (l > r) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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
