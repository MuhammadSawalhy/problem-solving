// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, c, d;
    cin >> n >> c >> d;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);


    int i = 0;

    int x = 0, y = 0;
    ll ans = n * c + d;
    for (int i = 0; i < n; i++) {
        x += i > 0 && a[i] == a[i - 1];
        y += i == 0 || a[i] != a[i - 1];
        ans = min(ans, 1LL * d * (a[i] - y) + 1LL * c * (n - i - 1 + x));
    }

    cout << ans << '\n';
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
