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
    int n, m, d, ans = INT_MAX;
    cin >> n >> m >> d;
    vector<long long> a(m), p(n);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        pos[p[i]] = i + 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < m - 1; ++i) {
        int x1 = pos[a[i]], x2 = pos[a[i + 1]], x3 = pos[a[i]] + d;
        if (x1 < x2 and x2 <= x3) {
            int t = INT_MAX;
            int curr_sep = x2 - x1;
            t = curr_sep + x1 - 1 + n - x2;
            if (1 + d < n) {
                t = d + 1 - curr_sep;
            } else
                t = INT_MAX;
            t = min(t, x2 - x1);
            ans = min(ans, t);
        } else {
            ans = 0;
        }
    }
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
