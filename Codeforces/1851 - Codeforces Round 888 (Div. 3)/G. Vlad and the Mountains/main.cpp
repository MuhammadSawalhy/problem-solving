// ﷽
// https://codeforces.com/contest/1851/problem/G
// Codeforces -> Codeforces Round 888 (Div. 3) -> G. Vlad and the Mountains

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
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

void solve() {
    int n, m;
    cin >> n >> m;
    int h[n];
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<int> order(n);
    iota(all(order), 0);
    sort(all(order), [&](int i, int j) { return h[i] < h[j]; });

    vector<int> adj[n];
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        u--, v--;
        if (h[u] < h[v]) swap(u, v);
        adj[u].push_back(v);
    }

    int q;
    cin >> q;
    vector<bool> ans(q);
    vector<array<int, 4>> queries;
    for (int i = 0; i < q; i++) {
        int a, b, e;
        cin >> a >> b >> e;
        queries.push_back({e + h[a - 1], a - 1, b - 1, i});
    }

    sort(all(queries));
    int k = 0;
    DSU dsu(n);

    for (auto i: order) {
        while (k < q && queries[k][0] < h[i]) {
            debug(queries[k]);
            ans[queries[k][3]] = dsu.connected(queries[k][1], queries[k][2]);
            k++;
        }
        for (auto j: adj[i]) {
            dsu.uni(i, j);
        }
    }

    while (k < q) {
        ans[queries[k][3]] = dsu.connected(queries[k][1], queries[k][2]);
        k++;
    }

    for (auto a: ans) {
        cout << (a ? "YES" : "NO") << '\n';
    }
    cout << '\n';
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
