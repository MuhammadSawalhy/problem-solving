#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif


struct DSU {
    vector<int> size, parent;
    int forests;

    DSU(int n): forests(n) {
        size.assign(n, 1);
        parent.resize(n), iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) { // merge x into y
        x = find(x), y = find(y);
        if (x == y) return false;
        forests--;
        parent[x] = y;
        size[y] += size[x];
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    int u[m], v[m], w[m];
    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i] >> w[i];
        u[i]--, v[i]--;
    }

    DSU dsu(n);

    vector<int> order(m);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return w[i] < w[j]; });

    int ans = 1e18;
    vector<int> mn(n, 1e18);

    for (auto i : order) {
        int cur = min(mn[dsu.find(u[i])], mn[dsu.find(v[i])]);
        dsu.uni(u[i], v[i]);
        mn[dsu.find(u[i])] = min(cur, w[i]);
        if (dsu.connected(0, n - 1)) {
            ans = min(ans, mn[dsu.find(0)] + w[i]);
        }
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("-----", t);
        solve();
    }

    return 0;
}
