// Date: 01-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

void solve() {
    int x, y;

    cin >> y >> x;

    int n = max(x, y);
    
    // our target lie on an ╝ shape (right and bottom edges of a square)

    ll s = 1LL * (n - 1) * (n - 1); // start counting here

    if (n & 1) {
        // count from bottom
        if (x > y) {
            cout << (ll) n * n - y + 1 << endl;
        } else {
            cout << s + x << endl;
        }
    } else {
        // count from top
        if (x > y) {
            cout << s + y << endl;
        } else {
            cout << (ll) n * n - x + 1 << endl;
        }
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
