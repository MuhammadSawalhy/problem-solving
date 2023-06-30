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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    if (n == 1) {
        cout << 0 << endl;
    }

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    ll ans = 0;

    // binary search the k-th smallest number then calc them

    auto count = [&](int mid) {
        ll cnt = 0;
        for (int i = 1; i < n; i++) {
            // a[j] * a[i] >= mid
            // a[j] >= mid / a[i]
            int j = lower_bound(a, a + i, (mid + a[i] - 1) / a[i]) - a;
            cnt += i - j;
        }
        return cnt;
    };

    auto check = [&](int mid) -> bool {
        return count(mid) >= k;
    };

    ll s = a[0] * a[1], e = a[n - 1] * a[n - 2] + 1;

    while (e - s > 1) {
        ll mid = (s + e) / 2;
        if (check(mid)) {
            s = mid;
        } else {
            e = mid;
        }
    }

    ans -= (count(s) - k) * s;
    debug(s, count(s), ans);

    int p[n];
    p[0] = a[0];

    for (int i = 1; i < n; i++) {
        p[i] = a[i] + p[i - 1];
    }

    for (int i = 1; i < n; i++) {
        // a[j] * a[i] >= mid
        // a[j] >= mid / a[i]
        int j = lower_bound(a, a + i, (s + a[i] - 1) / a[i]) - a;
        debug(i, j, (p[i - 1] - (j > 0 ? p[j - 1] : 0)));
        ans += (p[i - 1] - (j > 0 ? p[j - 1] : 0)) * a[i];
    }

    cout << ans << endl;

    return 0;
}
