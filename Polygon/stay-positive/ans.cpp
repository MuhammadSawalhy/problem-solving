// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

int solve(vector<int> &a) {
    int n = a.size();
    vector<long long> ps(n + 1), mnright(n + 2), mnleft(n + 2);

    for (int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + a[i];

    mnleft[0] = mnright[n + 1] = LONG_LONG_MAX;

    for (int i = n; i >= 1; i--)
        mnright[i] = min(mnright[i + 1], ps[i]);

    for (int i = 1; i <= n; i++)
        mnleft[i] = min(mnleft[i - 1], ps[i]);

    for (int i = 1; i <= n; i++) {
        debug(i, mnleft[i], mnright[i]);
        if (a[i - 1] >= 0 && mnright[i] >= ps[i - 1] && mnleft[i] >= -(ps[n] - ps[i - 1])) {
            return i;
        }
    }

    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << solve(a) << endl;
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
