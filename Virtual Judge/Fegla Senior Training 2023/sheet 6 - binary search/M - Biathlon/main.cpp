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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    array<int, 3> circles[n];
    for (int i = 0; i < n; i++) {
        cin >> circles[i][0] >> circles[i][1], circles[i][2] = i;
    }

    sort(circles, circles + n);

    int m;
    cin >> m;
    int ans[n], cnt = 0;

    memset(ans, -1, sizeof ans);

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        int k = lower_bound(circles, circles + n, array<int, 3>{x}) - circles;
        for (int j = k - 1; j <= k; j++) {
            if (j < 0 || j >= n) continue;
            auto [cx, r, I] = circles[j];
            if (ans[I] != -1) continue;
            ll dx = x - cx, dy = y;
            if (dx * dx + dy * dy <= r * r)
                ans[I] = i, cnt++;
        }
    }

    cout << cnt << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
