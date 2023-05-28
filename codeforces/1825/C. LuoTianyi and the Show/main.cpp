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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int first = 0, second = 0;
    vector<int> others;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1)
            first++;
        if (a[i] == -2)
            second++;
        if (a[i] > 0)
            others.push_back(a[i]);
    }

    sort(all(others));
    others.erase(unique(all(others)), others.end());

    debug(n, m);
    int ans = min(m, max(first, second) + (int) others.size());
    for (int i = 0; i < others.size(); i++) {
        int x = others[i];
        if (x > 0) {
            debug(x);
            int left = lower_bound(all(others), x) - others.begin();
            int right = others.size() - left - 1;
            debug(left, right);
            int cur = 1 + min(m - x, right + second) + min(x - 1, left + first);
            ans = max(ans, cur);
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
