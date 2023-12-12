// ﷽
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
    int n, k; cin >> n >> k; ll a[n], index[n + 1];
    for (int i = 0; i < n; i++) cin >> a[i], index[a[i]] = i;

    sort(a, a + n);

    int x = n;
    for (int i = 2; i <= n; i++) {
        if (index[i] < index[i - 1]) {
            x = i - 1;
            break;
        }
    }

    cout << (n - x + k - 1) / k << endl;
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
