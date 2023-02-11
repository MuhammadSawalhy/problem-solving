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
    long long s = 0;
    int negs = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) cin >> a[i], zero |= a[i] == 0, s += abs(a[i]), negs += a[i] < 0, a[i] = abs(a[i]);
    if (zero) cout << s << endl;
    else if (negs & 1) cout << s - 2 * *min_element(a, a + n) << endl;
    else cout << s << endl;
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
