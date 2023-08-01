// ﷽
#include <bits/stdc++.h>

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

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, x;
    cin >> n >> x;
    pair<int, int> a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;

    sort(a, a + n);

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int y = x - a[i].first - a[j].first;
            int l = lower_bound(a, a + n, make_pair(y, 0LL)) - a;
            int u = upper_bound(a, a + n, make_pair(y, n)) - a;
            if (u - l > (a[i].first == y) + (a[j].first == y)) {
                for (int k = l; k < u; k++) {
                    if (k == i || k == j) continue;
                    cout << a[i].second + 1 << " " << a[j].second + 1 << " " << a[k].second + 1 << endl;
                    return 0;
                }
                assert(false);
            }
        }

    cout << "IMPOSSIBLE" << endl;

    return 0;
}
