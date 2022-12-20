// Date: 17-12-2022
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define all(v) v.begin(), v.end()
#define debug(...)
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[m];
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    if (k > m) {
        cout << "NO" << endl;
        return;
    }

    // n / k groups

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] <= (n) / k) {
        } else if (a[i] == (n + k - 1) / k) {
            cnt++;
        } else {
            cout << "NO" << endl;
            return;
        }
    }

    if (cnt != n % k) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
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
