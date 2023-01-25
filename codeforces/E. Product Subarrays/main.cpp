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
    int n;
    cin >> n;
    ll a[n];
    int p[n + 1];
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] = max(min(a[i], 1LL), -1LL);
        p[i + 1] = p[i] * a[i];
    }

    int ans[3] = {};
    int last_zero = 0;
    int last_pos = 0, last_neg = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i - 1] == 0) {
            last_zero = i;
            last_pos = last_neg = 0;
        } else {
            if (a[i - 1] == 1) {
                last_pos = last_pos + 1;
            } else {
                int temp = last_neg;
                last_neg = last_pos + 1;
                last_pos = temp;
            }
        }
        ans[0] += last_pos;
        ans[1] += last_neg;
        ans[2] += last_zero;
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
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
