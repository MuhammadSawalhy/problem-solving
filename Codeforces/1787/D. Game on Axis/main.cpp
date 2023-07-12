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

#define int    long long
#define ll     long long
#define all(v) v.begin(), v.end()

void solve() {
    int n;
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    int good = 0;
    vector<int> prev(n + 1);
    vector<bool> vis(n);
    vector<bool> onmain(n);
    vector<bool> isgood(n);

    function<bool(int)> dfs = [&](int i) -> bool {
        if (i >= n || i < 0) return true;
        if (vis[i]) return isgood[i];
        vis[i] = true;
        bool ok = dfs(i + a[i]);
        isgood[i] = ok;
        good += ok;
        return ok;
    };

    function<void(int)> dfs2 = [&](int i) {
        if (i >= n || i < 0) return;
        if (onmain[i]) return;
        onmain[i] = true;
        dfs2(i + a[i]);
    };

    dfs2(0);

    for (int i = 0; i < n; i++)
        dfs(i);

    vector<int> indeg(n + 1);
    vector<int> next(n + 1, -1);

    for (int i = 0; i < n; i++) {
        if (i + a[i] < 0 || i + a[i] >= n) {
            indeg[n]++;
            next[i] = n;
        } else {
            indeg[i + a[i]]++;
            next[i] = i + a[i];
        }
    }

    queue<int> qu;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            qu.push(i);
    }

    while (qu.size()) {
        int i = qu.front();
        qu.pop();
        if (next[i] != -1) {
            indeg[next[i]]--;
            if (indeg[next[i]] == 0)
                qu.push(next[i]);
            prev[next[i]] += prev[i] + 1;
        }
    }

    debug(prev);

    int ans = n * (2 * n + 1);
    for (int i = 0; i < n; i++) {
        if (onmain[i]) {
            if (isgood[0]) {
                ans -= (n - good) + prev[i] + 1;
            } else {
                ans -= (n - good);
            }
        } else {
            if (isgood[0]) {
            } else {
                ans -= 2 * n + 1;
            }
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
