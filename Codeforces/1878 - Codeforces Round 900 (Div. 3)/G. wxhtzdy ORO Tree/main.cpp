// بسم الله الرحمن الرحيم
// https://codeforces.com/contest/1878/problem/G
// Codeforces -> Codeforces Round 900 (Div. 3) -> G. wxhtzdy ORO Tree

#include <bits/stdc++.h>
#include <iomanip>
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

struct LCA {
    int n, LOG, _time;
    vector<int> first, depth;
    vector<vector<int>> adj, table;

    LCA(int n) : n(n), LOG(log2(n) + 3) {
        adj.resize(n), depth.resize(n), first.resize(n);
        table.assign(LOG, vector<int>(2 * n));
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int p) {
        first[u] = _time;
        table[0][_time++] = u;
        for (auto v: adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
            table[0][_time++] = u;
        }
    }

    void build(int root = 0) {
        _time = 0;
        dfs(root, root);
        assert(_time < 2 * n);
        for (int i = 1; i < LOG; i++) {
            for (int j = 0; j + (1 << i) <= 2 * n; j++) {
                if (depth[table[i - 1][j]] < depth[table[i - 1][j + (1 << (i - 1))]]) {
                    table[i][j] = table[i - 1][j];
                } else {
                    table[i][j] = table[i - 1][j + (1 << (i - 1))];
                }
            }
        }
    }

    int query(int u, int v) const {
        u = first[u], v = first[v];
        if (u == v) return table[0][u];
        if (u > v) swap(u, v);
        int lg = 31 - __builtin_clz(v - u + 1);
        if (depth[table[lg][u]] < depth[table[lg][v - (1 << lg) + 1]]) {
            return table[lg][u];
        } else {
            return table[lg][v - (1 << lg) + 1];
        }
    }
};

const int N = 2e5 + 5;
vector<int> adj[N];
int n, a[N];
int cnt[N][30], first[N][30];

void dfs(int i, int p) {
    for (int b = 0; b < 30; b++)
        if (a[i] >> b & 1)
            first[i][b] = i;
        else
            first[i][b] = first[p][b];
    for (int b = 0; b < 30; b++)
        cnt[i][b] = cnt[p][b] + (a[i] >> b & 1);
    for (auto j: adj[i])
        if (j != p)
            dfs(j, i);
}

int get_OR(int x, int y, int lc) {
    int total[30] = {};
    for (int i = 0; i < 30; i++)
        total[i] = cnt[x][i] + cnt[y][i] - cnt[lc][i] * 2;
    int val = 0;
    for (int i = 0; i < 30; i++)
        val |= (total[i] > 0) << i;
    return a[lc] | val;
}

int query(int x, int y, int lc) {
    vector<int> verts{y};

    int bits = get_OR(y, lc, lc) ^ a[y];
    for (int i = 0; i < 30; i++) {
        if (bits >> i & 1)
            verts.push_back(first[y][i]);
    }

    int ans = 0;

    for (auto i: verts) {
        maxit(ans, 0LL + __popcount(get_OR(x, i, lc)) + __popcount(get_OR(y, i, i)));
    }

    return ans;
}

void solve() {
    cin >> n;
    LCA lca(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        lca.add_edge(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < 30; i++)
        cnt[n][i] = 0;
    dfs(0, n);
    lca.build();

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y, x--, y--;
        int lc = lca.query(x, y);
        cout << max(query(x, y, lc), query(y, x, lc)) << ' ';
    }
    cout << '\n';

    for (int i = 0; i < n; i++) adj[i].clear();
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
