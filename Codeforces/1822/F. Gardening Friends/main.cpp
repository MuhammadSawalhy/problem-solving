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
    int n, k, c;
    cin >> n >> k >> c;
    vector<int> adj[n];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> mx(n);
    multiset<int> mxchild[n];
    function<int(int, int)> calcmx = [&](int i, int p) {
        int d = 0;
        for (auto j: adj[i]) {
            if (j == p) continue;
            int x = calcmx(j, i);
            d = max(d, x + 1);
            mxchild[i].insert(x);
        }
        mx[i] = d;
        return d;
    };

    calcmx(0, 0);

    int ans = -1e18;

    debug(n, c);
    function<void(int, int, int, int)> go = [&](int i, int p, int cost, int outermx) {
        debug(i, mx[i], outermx);
        ans = max(ans, max(mx[i], outermx) * k - cost);
        for (auto j: adj[i]) {
            if (j == p) continue;
            mxchild[i].erase(mxchild[i].find(mx[j]));
            int brothers = 0;
            if (mxchild[i].size()) {
                brothers = *prev(mxchild[i].end()) + 2;
            }
            debug(i, j, brothers, mxchild[i]);
            go(j, i, cost + c, max(brothers, outermx + 1));
            mxchild[i].insert(mx[j]);
        }
    };

    go(0, 0, 0, 0);

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
