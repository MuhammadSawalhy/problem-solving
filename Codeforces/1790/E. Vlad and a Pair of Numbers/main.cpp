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
    int x; cin >> x;

    if (x & 1) {
        cout << -1 << endl;
        return;
    }

    int a = 0, b = 0;
    for (int i = 1; i < 30; i++) {
        if ((x >> i) & 1 && (x >> (i - 1)) & 1) {
            cout << -1 << endl;
            return;
        }
        if ((x >> i) & 1) {
            a |= 1 << (i - 1);
            b |= 1 << i;
            b |= 1 << (i - 1);
        }
    }

    assert((a ^ b) == x);
    assert((a + b) / 2 == x);
    assert((a + b) % 2 == 0);

    cout << a << " " << b << endl;
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
