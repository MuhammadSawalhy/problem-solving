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
#define all(v) v.begin(), v.end()

const int N = 2e5;
vector<int> adj[N];
bool visited[N];
int first[N], last[N], value[N], parent[N];
vector<int> euler, values;
map<pair<int, int>, int> res;

void dfs(int node, int p) {
    visited[node] = true;
    parent[node] = p;
    first[node] = euler.size();
    euler.push_back(node);
    values.push_back(value[node]);
    for (auto to: adj[node]) {
        if (!visited[to]) {
            dfs(to, node);
        }
    }
    last[node] = euler.size() - 1;
}

template<typename T>
struct Node {
    T value;

    Node(T value = 0) : value(value) {}

    void operator+=(const Node &other) {
        value = max(value, other.value);
    }

    Node operator+(const Node &other) {
        return max(value, other.value);
    }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct segtree {
    int n;
    vector<Node<T>> tree;

    segtree(int n) : n(n) {
        tree.resize(n * 2);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
            tree[i >> 1] = tree[i] + tree[i ^ 1];
    }

    T query(int l, int r) {
        Node<T> res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res.value;
    }
};

int block_size;

struct MO {
    struct Query {
        int l, r, idx;
        Query(int l, int r, int idx) : l(l), r(r), idx(idx) {}
        bool operator<(const Query &q) const {
            if (l / block_size != q.l / block_size)
                return pair(l, r) < pair(q.l, q.r);
            return (l / block_size & 1) ? (r < q.r) : (r > q.r);
        }
    };

    vector<int> arr;
    vector<Query> queries;
    vector<int> fr = vector<int>(N);
    segtree<int> sg = segtree<int>(0);

    MO(vector<int> &arr, vector<Query> &queries) : arr(arr), queries(queries) {
        sg = segtree<int>(arr.size() + 1);
    }

    int l = 0, r = -1;

    void set_range(Query &q) {
        // [l, r] inclusive
        while (l > q.l) add(arr[--l]);
        while (r < q.r) add(arr[++r]);
        while (l < q.l) remove(arr[l++]);
        while (r > q.r) remove(arr[r--]);
    }

    void add(int x) {
        fr[x]++;
        if (fr[x] == 2)
            sg.update(x, x);
    }

    void remove(int x) {
        fr[x]--;
        if (fr[x] == 1)
            sg.update(x, 0);
    }

    int getans(Query &q) {
        return sg.query(0, arr.size());
    }

    vector<int> ans() {
        block_size = sqrt(arr.size()) + 1;
        vector<int> ans(queries.size());
        sort(all(queries));

        l = queries.front().l, r = queries.front().l - 1;
        for (auto &q: queries) {
            set_range(q);
            ans[q.idx] = getans(q);
            debug(l, r, ans[q.idx]);
        }

        return ans;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges[i] = pair(u, v);
    }

    for (int i = 0; i < n; i++)
        cin >> value[i];


    dfs(0, 0);
    assert(values.size() == n);

    // queries using MO algorithm
    vector<MO::Query> queries;
    for (int i = 1; i < n; i++) {
        queries.emplace_back(first[i], last[i], (i - 1) * 2);
        queries.emplace_back(last[i] + 1, n + first[i] - 1, (i - 1) * 2 + 1);
    }

    int x = 1;
    map<int, int> mapper;
    vector<int> rev(values.size());

    vector<int> valcopy = values;
    sort(all(valcopy));
    for (int i = 0; i < n; i++) {
        if (mapper.count(valcopy[i])) continue;
        rev[x] = valcopy[i];
        mapper[valcopy[i]] = x++;
    }

    for (int i = 0; i < n; i++) {
        values[i] = mapper[values[i]];
    }

    for (int i = 0; i < n; i++) {
        values.push_back(values[i]);
    }

    auto ans = MO(values, queries).ans();

    for (int i = 1, j = 0; i < n; i += 1, j += 2) {
        res[{parent[i], i}] = res[{i, parent[i]}] = max(ans[j], ans[j + 1]);
    }

    for (int i = 0; i < n - 1; i++) {
        cout << rev[res[edges[i]]] << '\n';
    }

    return 0;
}
