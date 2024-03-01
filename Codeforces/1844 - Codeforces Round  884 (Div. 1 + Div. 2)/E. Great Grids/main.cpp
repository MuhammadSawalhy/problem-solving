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

struct DSU {
    vector<int> size, parent;
    int forests;

    DSU(int n) {
        forests = n;
        size.assign(n, 1);
        parent.resize(n);
        iota(all(parent), 0);
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        forests--;
        parent[y] = x;
        size[x] += size[y];
        return true;
    }
};

int n, m, k;

pair<int, int> getRow(int x) {
    return { x, n + x };
}

pair<int, int> getCol(int x) {
    return { n + n + x, n + n + m + x };
}

void solve() {
    cin >> n >> m >> k;
    DSU dsu((n + m) << 1);

    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;
        if (y1 < y2) {
            auto [r, ir] = getRow(x1);
            auto [c, ic] = getCol(y1);
            // diff
            dsu.uni(r, ic);
            dsu.uni(ir, c);
        } else {
            auto [r, ir] = getRow(x1);
            auto [c, ic] = getCol(y2);
            // same
            dsu.uni(r, c);
            dsu.uni(ir, ic);
        }
    }

    for (int i = 0; i < n; i++) {
        auto [r, ir] = getRow(i);
        if (dsu.connected(r, ir)) {
            cout << "NO\n";
            return;
        }
    }

    for (int i = 0; i < m; i++) {
        auto [c, ic] = getCol(i);
        if (dsu.connected(c, ic)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
