// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

// clang-format off
template <typename T> struct Node {
    T value = 0;
    ll relative_update = 0;
    bool pending_update = false;
    Node(){};
    Node(T value) : value(value){};

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void update(const T &val) {
        value = val;
        relative_update = 0;
        pending_update = true;
    }

    void relupdate(const T &val) {
        relative_update += val;
    }

    void propagate(int node, vector<Node<T>> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        if (pending_update) {
            if (left < sz) {
                tree[left].value = value;
                tree[left].relative_update = 0;
                tree[left].pending_update = true;
            }
            if (right < sz) {
                tree[right].value = value;
                tree[right].relative_update = 0;
                tree[right].pending_update = true;
            }
            pending_update = false;
        }

        value += count_children(node, sz) * relative_update;
        if (left < sz)
            tree[left].relative_update += relative_update;
        if (right < sz)
            tree[right].relative_update += relative_update;
        relative_update = 0;
    }

    friend ostream& operator<<(ostream &cout, const Node<T> &n) {
        cout << "(value: " << n.value << ", rel: " << n.relative_update << ")";
        return cout;
    }
};

template <typename T> struct segtree {
    int n;
    T default_value;
    vector<Node<T>> tree;
    function<T(T, T)> operation;

    segtree(int n, T default_value, function<T(T, T)> operation) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        this->operation = operation;
        this->default_value = default_value;
        tree.assign(n << 1, default_value);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = operation(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int i, int j, T val) {
        update(1, 0, n - 1, i, j, val);
    }

    void update(int i, T val) {
        update(i, i, val);
    }

    void relative_update(int i, int j, ll val) {
        relative_update(1, 0, n - 1, i, j, val);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

    int lower_bound(int x) {
        return lower_bound(x, 1, 0, n - 1);
    }

private:
    T query(int node, int node_low, int node_high, int query_low, int query_high) {
        tree[node].propagate(node, tree);
        if (query_high < node_low || node_high < query_low) return default_value;
        if (query_low <= node_low && node_high <= query_high) return tree[node].value;

        int mid = (node_high + node_low) >> 1;
        const T &l = query(node << 1, node_low, mid, query_low, query_high);
        const T &r = query(node << 1 | 1, mid + 1, node_high, query_low, query_high);

        return operation(l, r);
    }

    void update(int node, int node_low, int node_high,
                     int query_low, int query_high, const T &val) {
        tree[node].propagate(node, tree);
        if (query_high < node_low || node_high < query_low) return;
        if (query_low <= node_low && node_high <= query_high) {
            tree[node].update(val);
            tree[node].propagate(node, tree);
            return;
        }

        int mid = (node_high + node_low) >> 1;
        update(node << 1, node_low, mid, query_low, query_high, val);
        update(node << 1 | 1, mid + 1, node_high, query_low, query_high, val);
        tree[node].value = operation(tree[node << 1].value, tree[node << 1 | 1].value);
    }

    void relative_update(int node, int node_low, int node_high,
                     int query_low, int query_high, const T &val) {
        tree[node].propagate(node, tree);
        if (query_high < node_low || node_high < query_low) return;
        if (query_low <= node_low && node_high <= query_high) {
            tree[node].relupdate(val);
            tree[node].propagate(node, tree);
            return;
        }

        int mid = (node_high + node_low) >> 1;
        relative_update(node << 1, node_low, mid, query_low, query_high, val);
        relative_update(node << 1 | 1, mid + 1, node_high, query_low, query_high, val);
        tree[node].value = operation(tree[node << 1].value, tree[node << 1 | 1].value);
    }

    int lower_bound(int x, int node, int node_low, int node_high) {
        if (node_low == node_high) return node_low;
        int mid = (node_low + node_high) / 2;
        if (tree[node << 1].value >= x)
            return lower_bound(x, node << 1, node_low, mid);
        return lower_bound(x - tree[node << 1].value, node << 1 | 1, mid + 1, node_high);
    }
};
// clang-format on

void solve(int &x, int y) {
    while (y--) {
        if (x < 10)
            break;
        int r = 0;
        while (x) {
            r += x % 10;
            x /= 10;
        }
        x = r;
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    int a[n];
    segtree<ll> sg(n, 0, [](ll l, ll r) { return l + r; });
    for (int i = 0; i < n; i++) cin >> a[i];

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            cin >> l >> r, l--, r--;
            sg.relative_update(l, r, 1);
        } else {
            int x;
            cin >> x, x--;
            int y = sg.query(x, x);
            solve(a[x], y);
            cout << a[x] << endl;
            sg.update(x, 0);
        }
    }
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
