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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = a;
    if (a) {
        ans += 2 * min(b, c);
        int x = max(b, c) - min(b, c) + d;
        ans += min(a + 1, x);
        cout << ans << endl;
    } else {
        cout << 1 << endl;
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
