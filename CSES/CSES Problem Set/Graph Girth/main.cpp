// ﷽
// https://cses.fi/problemset/task/1707

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

// source: https://codeforces.com/blog/entry/18051
struct Segtree {
    int n;
    vector<int> tree;

    Segtree() = default;
    Segtree(int n) : n(n) {
        tree.resize(n * 2);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, int val, bool forces) {
        for (forces ? tree[i += n] = val : tree[i] = max(tree[i += n], val); i > 1; i >>= 1)
            tree[i >> 1] = max(tree[i], tree[i ^ 1]);
    }

    auto query(int l, int r) {
        int res = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(tree[l++], res);
            if (r & 1) res = max(tree[--r], res);
        }
        return res;
    }
};


const int N = 2505;
Segtree sg(N);
int D[N], ans = 1e9;
vector<int> adj[N];
vector<int> newadj[N];
bool vis[N];

void dfs(int i, int p) {
    vector<pair<int, int>> sg_updates;
    vector<int> back_nodes;
    multiset<int> back_depths;

    // calc back_nodes
    for (auto j: adj[i]) {
        if (j == p) continue;
        if (D[j] && D[j] < D[i]) {
            // back edge here
            back_nodes.push_back(j);
            back_depths.insert(D[j]);
            newadj[j].push_back(i);
            newadj[i].push_back(j);
        }
    }

    // calc ans
    for (auto j: back_nodes) {
        // get contribution from back_depths and sg
        auto Q = sg.query(D[j], D[i]);
        back_depths.erase(back_depths.find(D[j]));
        // min depth >= D[j]
        auto Q2 = back_depths.lower_bound(D[j]);
        if (Q2 != back_depths.end())
            minit(ans, D[i] - D[j] + 1 - max(Q, D[i] - *Q2 - 1));
        minit(ans, D[i] - D[j] + 1 - Q);
        back_depths.insert(D[j]);
    }

    // apply back_nodes
    for (auto j: back_nodes) {
        auto q = sg.tree[D[j] + sg.n];
        sg_updates.push_back({D[j], q});
        sg.update(D[j], D[i] - D[j] - 1, false);
    }

    // dfs to children
    for (auto j: adj[i]) {
        if (j == p) continue;
        if (D[j] == 0) {
            D[j] = D[i] + 1;
            dfs(j, i);
        }
    }

    // revert updates
    reverse(all(sg_updates));
    for (auto [d, v]: sg_updates) {
        sg.update(d, v, true);
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        if (u == v) {
            cout << 1 << endl;
            return 0;
        }
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int iters = log(n) / log(3) + 1; iters; iters--) {
        for (int i = 1; i <= n; i++) {
            if (D[i] == 0) {
                D[i] = 1;
                dfs(i, i);
            }
        }

        if (iters == 1) break;

        int j = 0;
        for (int i = 1; i <= n; i++) {
            D[i] = 0;
            adj[i] = newadj[i];
            newadj[i].clear();
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;

    return 0;
}
