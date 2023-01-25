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
    int n; cin >> n; ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] % 2 != a[i - 1] % 2) {
            ans += i - j - 1;
            j = i;
        }
    }

    ans += n - j - 1;

    cout << ans << endl;
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
