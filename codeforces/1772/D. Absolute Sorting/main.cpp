// Date: 18-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    int n;
    cin >> n;
    ll a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int x;
    if (a[1] > a[0]) {
        x = (a[0] + a[1]) / 2;
    } else {
        x = (a[0] + a[1] + 1) / 2;
    }

    for (int i = 0; i < n; i++) {
        a[i] = abs(a[i] - x);
    }

    if (is_sorted(a, a + n)) {
        cout << x << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
