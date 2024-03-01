// ﷽
// https://codeforces.com/contest/1793/problem/E

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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> ans(3 * n), dp(n + 1);

    sort(all(a));
    for (int i = 1; i <= n; i++) {
        if (i - a[i] >= 0)
            dp[i] = dp[i - a[i]] + 1;
        if (dp[i] > 0)
            ans[dp[i] + n - i] = max(ans[dp[i] + n - i], i);
        maxit(dp[i], dp[i - 1]);
        ans[1 + n - max(a[i], i)] = max(ans[1 + n - max(a[i], i)], i);
        debug(i, dp[i]);
        debug(1 + n - a[i], dp[i] + n - i);
    }


    for (int i = 3 * n - 2; i > 0; i--) {
        debug(i, ans[i]);
        ans[i] = max(ans[i], ans[i + 1]);
    }

    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        cout << ans[k] << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
