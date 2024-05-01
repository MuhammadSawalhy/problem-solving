// ﷽
// https://codeforces.com/group/diAwUqxD2g/contest/519136/problem/I

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

const int N = 2e5 + 5, M = 1e3 + 1;
int vals[N];
bool node_fr[N];
int vals_fr[M * 2];
int vals_sum[M * 2];
vector<int> primes;

int block_size;
struct MO {
    struct Query {
        int l, r, idx, lc_value = -1;
        bool operator<(const Query &q) const {
            if (l / block_size != q.l / block_size)
                return pair(l, r) < pair(q.l, q.r);
            return (l / block_size & 1) ? (r < q.r) : (r > q.r);
        }
    };

    vector<int> arr;
    vector<Query> queries;
    int l = 0, r = -1;

    MO() {}
    MO(const vector<int> &arr) : arr(arr) {
        debug(arr);
    }

    void add_query(const Query &q) {
        queries.push_back(q);
    }

    vector<int> get_ans() {
        block_size = arr.size() / sqrt(queries.size()) + 1;
        vector<int> ans(queries.size());
        sort(all(queries));

        l = queries.front().l, r = queries.front().l - 1;
        for (auto &q: queries) {
            set_range(q);
            ans[q.idx] = ans_query(q);
        }

        set_range({queries.back().l, queries.back().l - 1});

        return ans;
    }

    void set_range(const Query &q) {
        // [l, r] inclusive
        while (l > q.l) add(arr[--l]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (r > q.r) remove(arr[r--]);
    }

    void add_node(int node) {
        debug("adding", node);
        node_fr[node] = !node_fr[node];
        vals_fr[vals[node]]++;
    }

    void remove_node(int node) {
        debug("removing", node);
        node_fr[node] = !node_fr[node];
        vals_fr[vals[node]]--;
    }

    void add(int node) {
        if (node_fr[node] == 0) {
            // add
            add_node(node);
        } else {
            remove_node(node);
        }
        if (!(node_fr[node] <= 2 && node_fr[node] >= 0)) {
            debug(node, node_fr[node]);
        }
        assert(node_fr[node] <= 2 && node_fr[node] >= 0);
    }

    void remove(int node) {
        if (node_fr[node] == 0) {
            // add
            add_node(node);
        } else {
            remove_node(node);
        }
        if (!(node_fr[node] <= 2 && node_fr[node] >= 0)) {
            debug(node, node_fr[node]);
        }
        assert(node_fr[node] <= 2 && node_fr[node] >= 0);
    }

    int ans_query(Query &q) {
        debug(q.l, q.r, q.lc_value);
        int ans = 1e9;
        if (q.lc_value != -1) {
            add_node(q.lc_value);
        }

        for (int i = 1; i < 2 * M; i++) {
            if (vals_fr[i]) {
                debug(i, vals_fr[i]);
            }
            vals_sum[i] = vals_fr[i] * i;
            vals_sum[i] += vals_sum[i - 1];
            vals_fr[i] += vals_fr[i - 1];
        }

        for (int p: primes) {
            int cur = 0;
            for (int mul = p; mul < M + p; mul += p) {
                int sum = vals_sum[mul - 1] - vals_sum[mul - p];
                int fr = vals_fr[mul - 1] - vals_fr[mul - p];
                if (fr * mul - sum < 0) debug(p, mul, sum, fr);
                cur += fr * mul - sum;
            }
            minit(ans, cur);
            if (p < 100)
                debug(p, ans);
        }

        for (int i = 2 * M - 1; i > 0; i--) {
            vals_fr[i] -= vals_fr[i - 1];
        }

        if (q.lc_value != -1) {
            remove_node(q.lc_value);
        }

        return ans;
    }
};

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

struct MOTree {
    vector<vector<int>> adj;
    vector<int> arr, st, en;
    int n;
    MO mo;
    LCA lca;

    MOTree(const vector<vector<int>> &adj) {
        this->adj = adj, n = adj.size();
        st.resize(n), en.resize(n);
        lca = LCA(adj);
        _dfs(0, 0);
        mo = MO(arr);
    }

    void _dfs(int i, int p) {
        st[i] = arr.size();
        arr.push_back(i);
        for (auto j: adj[i]) {
            if (p == j) continue;
            _dfs(j, i);
        }
        en[i] = arr.size();
        arr.push_back(i);
    }

    void add_query(int u, int v, MO::Query q) {
        if (st[u] > st[v]) swap(u, v);
        int lc = lca.query(u, v);
        if (lc == u) q.l = st[u], q.r = st[v];
        else q.l = en[u], q.r = st[v], q.lc_value = lc;
        mo.add_query(q);
    }

    auto get_ans() {
        return mo.get_ans();
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> vals[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    MOTree tree = MOTree(adj);
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        tree.add_query(u, v, {u, v, i});
    }

    vector<int> ans = tree.get_ans();
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    // freopen("./main_input0.txt", "r", stdin);

    vector<int> is_prime(M, 1);
    for (int i = 2; i < M; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * i; j < M; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
