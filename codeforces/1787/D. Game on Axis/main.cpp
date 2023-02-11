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
    for (int i = 0; i < n; i++) cin >> a[i];

    int good = 0;
    vector<int> extra(n);

    vector<bool> vis(n);
    vector<bool> isgood(n);

    function<bool(int)> dfs = [&](int i) -> bool {
        if (i >= n || i < 0) return true;
        if (a[i] == 0) return false;
        if (vis[i]) {
            return isgood[i];
        }
        vis[i] = true;
        bool ok = dfs(i + a[i]);
        isgood[i] = ok;
        extra[i] = good;
        good += ok;
        return ok;
    };

    int ans = (n + 1) * n;
    for (int i = 0; i < n; i++) {
        dfs(i);
        ans += extra[i];
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
