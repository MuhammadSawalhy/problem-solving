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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int inf = 1e18;
    vector<int> ans(n + 1, 0), val(n + 1, -inf);
    int cur = 0;
    for (int i = n - 1; ~i; i--) {
        if (val[a[i]] == -inf) {
            val[a[i]] = cur + i;
        } else {
            // either leaf it to be erased with similar number later, contribute to val[a[i]]
            // or erase it directly now, contribute to ans[a[i]]
            ans[a[i]] = max(ans[a[i]], val[a[i]] - i + 1);
            val[a[i]] = max(val[a[i]], cur + i);
            cur = max(cur, ans[a[i]]);
        }
    }

    cout << cur << '\n';
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
