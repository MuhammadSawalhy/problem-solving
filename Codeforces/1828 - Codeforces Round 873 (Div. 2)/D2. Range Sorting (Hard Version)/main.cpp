// ﷽
// https://codeforces.com/contest/1828/problem/D2

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
    int ans = 0;

    vector<int> a(n);
    map<int, int> ind;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        int m = n - i + 1;
        ans += m * (i - 1);
    }

    set<int> done, not_done;
    for (int i = 0; i <= n; i++) {
        not_done.insert(i);
    }

    sort(rall(a));

    debug(a);
    for (auto x: a) {
        debug(x);
        int i = ind[x];

        auto it = done.lower_bound(i);

        if (it != done.end()) {
            int next_lt = *not_done.upper_bound(*it);
            int prev_gt = it != done.begin() ? *prev(it) : -1;
            debug(prev_gt, i, *it, next_lt);
            ans -= (next_lt - *it) * (i - prev_gt);
        }

        done.insert(i);
        not_done.erase(i);
    }

    cout << ans << '\n';
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
