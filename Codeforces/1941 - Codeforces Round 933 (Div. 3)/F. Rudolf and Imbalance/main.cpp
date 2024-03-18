// ﷽
// https://codeforces.com/contest/1941/problem/F

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
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int a[n];
    int g[m];
    int f[k];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> g[i];
    for (int i = 0; i < k; i++) cin >> f[i];

    sort(a, a + n);
    sort(f, f + k);
    int mx = 0;

    int cnt = 0, I;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == mx) {
            cnt++;
        } else if (a[i] - a[i - 1] > mx) {
            mx = a[i] - a[i - 1];
            cnt = 1;
            I = i;
        }
    }

    if (cnt > 1) {
        cout << mx << endl;
        return;
    }

    assert(--I >= 0);

    int mn = mx;

    for (int i = 0; i < m; i++) {
        int target = a[I] + mx / 2;
        // search for f[j] such that g[i] + f[j] == target
        int j = lower_bound(f, f + k, target - g[i]) - f;
        for (int r = max(0ll, j - 10); r < min(j + 10, k); r++) {
            int x = f[r] + g[i] - a[I];
            mn = min(mn, max(mx - x, x));
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] == mx) continue;
        maxit(mn, a[i] - a[i - 1]);
    }

    cout << mn << endl;
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
