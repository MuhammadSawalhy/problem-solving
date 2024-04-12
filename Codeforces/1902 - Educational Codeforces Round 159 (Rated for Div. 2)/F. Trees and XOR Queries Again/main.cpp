// ﷽
// https://codeforces.com/contest/1902/problem/F

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

struct LCA {
    int n, LOG, _time;
    vector<int> first, depth;
    vector<vector<int>> table;

    LCA() {}
    LCA(const vector<vector<int>> &adj) { build(adj); }

    void _dfs(int u, int p, const vector<vector<int>> &adj) {
        first[u] = _time;
        table[0][_time++] = u;
        for (auto v: adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            _dfs(v, u, adj);
            table[0][_time++] = u;
        }
    }

    void build(const vector<vector<int>> &adj, int root = 0) {
        n = sz(adj), LOG = log2(n) + 3;
        depth.resize(n), first.resize(n);
        table.assign(LOG, vector<int>(2 * n));
        _time = 0;
        _dfs(root, root, adj);
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

template<int bits>
struct XORBasis {
    array<int, bits> basis;

    void reset() { basis = array<int, bits>(); }

    void insert(const vector<int> &v) {
        for (auto x: v) insert(x);
    }

    bool insert(int x) {
        for (int b = 0; x && b < bits; b++) {
            if (x >> b & 1 ^ 1) continue;
            if (!basis[b]) return basis[b] = x, true;
            x ^= basis[b];
        }
        return false;
    }

    int size() {
        int sz = 0;
        for (auto b: basis) sz += !!b;
        return sz;
    }

    int mask(int x) {
        int m = 0;
        for (int b = 0; b < bits; b++) {
            if (x >> b & 1 ^ 1) continue;
            if (!basis[b]) return -1;
            x ^= basis[b], m |= 1 << b;
        }
        if (x != 0) return -1;
        return m;
    }

    int reduce(int x) {
        for (int b = 0; x && b < bits; b++)
            if (x >> b & 1) x ^= basis[b];
        return x;
    }
};


const int N = 2e5 + 5;
int a[N], depth[N];
vector<vector<int>> adj;
vector<int> basis[N];
XORBasis<20> xb;

void dfs(int i, int p) {
    xb.reset();
    assert(!a[i] || xb.insert(a[i]));
    basis[i].push_back(i);

    if (p != i) {
        for (auto x: basis[p]) {
            if (xb.insert(a[x])) basis[i].push_back(x);
        }
    }

    for (auto j: adj[i]) {
        if (j == p) continue;
        depth[j] = depth[i] + 1;
        dfs(j, i);
    }
}

vector<int> vert_path_basis(int i, int p) {
    vector<int> res;
    for (auto x: basis[i]) {
        if (depth[x] < depth[p]) break;
        res.push_back(x);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    adj.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    LCA lca(adj);
    dfs(0, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v, k;
        cin >> u >> v >> k;
        u--, v--;

        xb.reset();
        int lc = lca.query(u, v);
        vector<int> f = vert_path_basis(u, lc);
        vector<int> s = vert_path_basis(v, lc);

        for (auto x: f)
            xb.insert(a[x]);
        for (auto x: s)
            xb.insert(a[x]);

        cout << (xb.mask(k) == -1 ? "NO" : "YES") << endl;
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
