// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << '\n';
        return;
    }

    if (n & 1) {
        cout << -1 << '\n';
        return;
    }

    cout << n << " ";
    int odd = n - 1;
    int even = 2;
    for (int i = 1; i < n; i++) {
        if (i & 1) {
            cout << odd << " ";
            odd -= 2;
        } else {
            cout << even << " ";
            even += 2;
        }
    }

    cout << '\n';
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
