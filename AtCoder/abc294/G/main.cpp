#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll  long long
const int MAXN = 2e5 + 5;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#endif

int N, Q, timer;
int dist[MAXN], subtree_start[MAXN], subtree_end[MAXN];

using ValueType = long long;

struct Node {
    ValueType sum = 0, mn = 1e18, mx = -1e18;
    ll relative_update = 0;
    bool pending_update = false;

    Node() = default;
    Node(ValueType value) { update(value); };

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void update(const ValueType &val) {
        sum = mn = mx = val;
        relative_update = 0;
        pending_update = true;
    }

    void propagate(int node, vector<Node> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        if (pending_update) {
            if (left < sz) tree[left].update(sum);
            if (right < sz) tree[right].update(sum);
            pending_update = false;
        }

        relupdate(count_children(node, sz));
        if (left < sz) tree[left].relative_update += relative_update;
        if (right < sz) tree[right].relative_update += relative_update;
        relative_update = 0;
    }

    void relupdate(int cnt) {
        sum += 1LL * cnt * relative_update;
        mn += relative_update;
        mx += relative_update;
    }

    Node operator+(const Node &other) const {
        Node ans = *this;
        ans.sum += other.sum;
        ans.mn = min(ans.mn, other.mn);
        ans.mx = max(ans.mx, other.mx);
        return ans;
    }
};

struct segtree {
    int n;
    vector<Node> tree;

    segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node());
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, int j, const ValueType &val) {
        update(1, 0, n - 1, i, j, val);
    }

    void update(int i, const ValueType &val) {
        update(i, i, val);
    }

    void relative_update(int i, int j, ll val) {
        relative_update(1, 0, n - 1, i, j, val);
    }

    Node query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    int lower_bound(const ValueType &x) {
        return lower_bound(x, 1, 0, n - 1);
    }

private:
    Node query(int i, int l, int r, int L, int R) {
        tree[i].propagate(i, tree);
        if (R < l || r < L) return Node(); // default
        if (L <= l && r <= R) return tree[i];

        int mid = (r + l) >> 1;
        const auto &lval = query(i << 1, l, mid, L, R);
        const auto &rval = query(i << 1 | 1, mid + 1, r, L, R);

        return lval + rval;
    }

    void update(int i, int l, int r, int L, int R, const ValueType &val) {
        tree[i].propagate(i, tree);
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            tree[i].update(val);
            tree[i].propagate(i, tree);
            return;
        }

        int mid = (r + l) >> 1;
        update(i << 1, l, mid, L, R, val);
        update(i << 1 | 1, mid + 1, r, L, R, val);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void relative_update(int i, int l, int r, int L, int R, ll val) {
        tree[i].propagate(i, tree);
        if (R < l || r < L) return;
        if (L <= l && r <= R) {
            tree[i].relative_update += val;
            tree[i].propagate(i, tree);
            return;
        }

        int mid = (r + l) >> 1;
        relative_update(i << 1, l, mid, L, R, val);
        relative_update(i << 1 | 1, mid + 1, r, L, R, val);
        tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    int lower_bound(const ValueType &x, int i, int l, int r) {
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (tree[i << 1].sum >= x)
            return lower_bound(x, i << 1, l, mid);
        return lower_bound(x - tree[i << 1].sum, i << 1 | 1, mid + 1, r);
    }
};

segtree sg(0);

struct LCA {
    int n, LOG;
    vector<int> depth;
    vector<vector<int>> parent;
    vector<vector<pair<int, int>>> adj;

    LCA() : n(0), LOG(-1e9) {}

    LCA(const vector<vector<pair<int, int>>> &adj, int root = 0) : adj(adj), n(adj.size()), LOG(log2(n) + 3) {
        depth.resize(n);
        parent = vector<vector<int>>(n, vector<int>(LOG, root));
        preprocess(root);
    }

    void dfs(int u, int p) {
        timer++;
        subtree_start[u] = timer;
        for (auto [v, w]: adj[u]) {
            if (v == p) continue;
            parent[v][0] = u;
            depth[v] = depth[u] + 1;
            dist[v] = dist[u] + w;
            dfs(v, u);
        }
        subtree_end[u] = timer;
    }

    void preprocess(int root) {
        dfs(root, root);
        for (int k = 1; k < LOG; k++)
            for (int u = 0; u < n; u++)
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
    }

    int query(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int k = LOG - 1; k >= 0; k--) {
            if (depth[parent[u][k]] >= depth[v]) {
                u = parent[u][k];
            }
        }
        if (u == v) return u;
        for (int k = LOG - 1; k >= 0; k--) {
            if (parent[u][k] != parent[v][k]) {
                u = parent[u][k];
                v = parent[v][k];
            }
        }
        return parent[u][0];
    }
};

LCA lca;

int distance(int u, int v) {
    int p = lca.query(u, v);
    p = subtree_start[p];
    u = subtree_start[u];
    v = subtree_start[v];
    return sg.query(u, u).sum + sg.query(v, v).sum - 2 * sg.query(p, p).sum;
}

void update(array<int, 3> &edge, int w) {
    auto [a, b, ww] = edge;
    if (lca.parent[a][0] == b) swap(a, b);
    sg.relative_update(subtree_start[b], subtree_end[b], w - ww);
    edge[2] += w - ww;
}

int32_t main() {
    cin >> N;
    array<int, 3> edges[N];
    vector<vector<pair<int, int>>> adj(N);
    for (int i = 1; i < N; i++) {
        int u, v, w;
        cin >> u >> v >> w, u--, v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges[i] = {u, v, w};
    }

    lca = LCA(adj);
    sg = segtree(N + 1);

    for (int i = 0; i < N; i++) {
        sg.update(subtree_start[i], dist[i]);
    }

    cin >> Q;
    while (Q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int e, w;
            cin >> e >> w;
            update(edges[e], w);
        } else {
            int u, v;
            cin >> u >> v, u--, v--;
            cout << distance(u, v) << endl;
        }
    }

    return 0;
}
