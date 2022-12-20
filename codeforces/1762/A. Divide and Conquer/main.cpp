// Date: 15-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

int to_odd(int x) {
    int cnt = 0;
    while (x != 0 && x % 2 == 0) {
        x /= 2;
        cnt++;
    }

    return x == 0 ? 1e5 : cnt;
}

int to_even(int x) {
    int cnt = 0;
    while (x & 1) {
        x /= 2;
        cnt++;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2 == 0) {
        cout << 0 << endl;
        return;
    }

    int ans = 1e5;

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            ans = min(ans, to_even(a[i]));
        } else {
            ans = min(ans, to_odd(a[i]));
        }
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
