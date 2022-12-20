// Date: 16-12-2022
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

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }

    sort(a + 1, a + n);

    ll ans = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < ans) continue;
        ans = (ans + a[i] + 1) / 2;
    }

    cout << ans << endl;
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
