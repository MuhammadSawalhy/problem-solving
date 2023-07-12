// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

using ValueType = ll;

struct Node {
    ValueType mn = 1e18;
    int index = -1;
    ll relative_update = 0;
    bool pending_update = false;

    Node() = default;
    Node(ValueType value) { update(value); };

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void update(const ValueType &val) {
        mn = val;
        relative_update = 0;
        pending_update = true;
    }

    void propagate(int node, vector<Node> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        relupdate(count_children(node, sz));
        if (left < sz) tree[left].relative_update += relative_update;
        if (right < sz) tree[right].relative_update += relative_update;
        relative_update = 0;
    }

    void relupdate(int cnt) {
        mn += relative_update;
    }

    Node operator+(const Node &other) const {
        Node ans = other;
        if (mn < other.mn || mn == other.mn && index < other.index) {
            ans = *this;
        }
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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    segtree sg(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sg.tree[sg.n + i].index = i;
        sg.tree[sg.n + i].mn = a[i];
    }

    sg.build();

    vector<int> ans;
    int i = 0;
    while (k--) {
        auto q = sg.query(i, n - k - 1);
        debug(k, i);
        ans.push_back(q.mn);
        i = q.index + 1;
    }

    for (auto i : ans)
        cout << i << " ";

    return 0;
}
