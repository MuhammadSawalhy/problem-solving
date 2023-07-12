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
    int a, b;
    cin >> a >> b;

    int ans = 1e9, sq = sqrtl(a + b);
    for (int x = max(1ll, sq - 100); x < sq + 100; x++) {
        // check: https://www.desmos.com/calculator/uik1whubqe
        //
        // let's take the derivative and iterate in a range around the local minimum
        // assume no ceiling....
        //
        // ans = (a + b) / x + x - 1
        // d[ans]/d[x] = -(a + b) / x^2 + 1
        // when 1st derivative is zero
        // x^2 = a + b

        ans = min(ans, (a + x - 1) / x + (b + x - 1) / x + x - 1);
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
