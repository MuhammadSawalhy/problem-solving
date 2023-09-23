// ﷽
// https://codeforces.com/contest/1873/problem/H
// Codeforces -> Codeforces Round 898 (Div. 4) -> H. Mad City

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
    int n, a, b;
    cin >> n >> a >> b;
    a--, b--;

    DSU dsu(n);
    int x, y;
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dsu.connected(u, v)) {
            x = u, y = v;
        }
        dsu.uni(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> cycle(n);
    vector<bool> mvis(n), vvis(n);

get_the_cycle : {
    vector<bool> vis(n);
    queue<int> qu;
    qu.push(x);
    vis[x] = true;
    vector<int> par(n, -1);
    while (qu.size()) {
        int i = qu.front();
        qu.pop();
        for (auto j: adj[i]) {
            if (par[i] == j) continue;
            if (vis[j]) {
                for (int p = i; p != -1; p = par[p]) cycle[p] = true;
                for (int p = j; p != -1; p = par[p]) cycle[p] = true;
                goto try_to_ecape;
            }
            qu.push(j);
            vis[j] = true;
            par[j] = i;
        }
    }
}

try_to_ecape : {
    queue<pair<int, int>> m, v;
    m.push({a, 0});
    v.push({b, 0});
    mvis[a] = true;
    vvis[b] = true;

    if (a == b) {
        cout << "NO\n";
        return;
    }

    if (cycle[b]) {
        cout << "YES\n";
        return;
    }

    debug(n);
    debug(cycle);
    while (m.size() && v.size()) {
        int cur = m.size() ? m.front().second : v.front().second;

        while (m.size() && m.front().second == cur) {
            auto [a, ad] = m.front();
            m.pop();
            for (auto j: adj[a]) {
                if (mvis[j]) continue;
                m.push({j, cur + 1});
                mvis[j] = true;
            }
        }

        while (v.size() && v.front().second == cur) {
            auto [b, bd] = v.front();
            v.pop();

            for (auto j: adj[b]) {
                if (mvis[j]) continue;
                if (vvis[j]) continue;

                if (cycle[j]) {
                    cout << "YES\n";
                    return;
                }

                v.push({j, cur + 1});
                vvis[j] = true;
            }
        }
    }
}

    cout << "NO\n";
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
