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

const ll INF = 1e18;

ll default_value[2][2] = {{INF, INF}, {INF, INF}};

using ValueType = ll[2][2];

struct Node {
    ValueType value;
    ll relative_update = 0;
    bool pending_update = false;

    Node() { set_value(default_value); };
    Node(const ValueType value) { update(value); };

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void update(const ValueType val) {
        set_value(val);
        relative_update = 0;
        pending_update = true;
    }

    void propagate(int node, vector<Node> &tree) { }
    void relupdate(int cnt) { }

    void set_value(const ValueType val) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                value[i][j] = val[i][j];
    }

    bool operator==(const ValueType val) const {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                if (value[i][j] != val[i][j])
                    return false;
        return true;
    }


    Node operator+(const Node &s) const {
        if (*this == default_value) return s;
        if (s == default_value) return *this;
        Node res;
        for (int x = 0; x < 2; x++)
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    if (i + j > 0)
                        for (int y = 0; y < 2; y++)
                            res.value[x][y] = min(res.value[x][y], value[x][i] + s.value[j][y]);
        return res;
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
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    int w[n];
    for (int i = 1; i < n; i++) cin >> w[i];

    segtree sg(n);

    for (int i = 1; i < n; i++) {
        Node v;
        v.value[0][0] = 0;
        v.value[1][1] = w[i];
        sg.update(i, v.value);
    }

    int q;
    cin >> q;
    while (q--) {
        int k, x;
        cin >> k >> x;
        Node v;
        v.value[0][0] = 0;
        v.value[1][1] = x;
        sg.update(k, v.value);
        cout << 2 * sg.query(1, n - 1).value[1][1] << '\n';
    }

    return 0;
}
