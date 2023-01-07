// ----------------------------------------------------------------------------
// Problem : C. Circular RMQ
// Author  : Muahmmad Assawalhy
// Date    : 17-09-22
// ----------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

// clang-format off
template <typename T> struct Node {
    T value = 0;
    ll relative_update = 0;
    bool pending_update = false;
    Node(){};
    Node(T value) : value(value){};

    static int count_children(int node, int tree_size) {
        return (tree_size / 2 + node - 1) / node;
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

        value += relative_update;
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
        if (__builtin_popcountll(n) > 1)
            n = 1 << (64 - __builtin_clzll(n));
        this->n = n;
        this->operation = operation;
        this->default_value = default_value;
        tree.assign(n << 1, default_value);
    }

    T query(int l, int r) {
        return query(1, 0, n - 1, l, r);
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
};
// clang-format on

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    //  freopen("../input", "r", stdin);
    int n;
    cin >> n;
    segtree<ll> sg(n, LONG_LONG_MAX, [](ll l, ll r) { return min(l, r); });

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sg.update(i, a);
    }

    int m;
    cin >> m;
    cin.ignore();
    while (m--) {
        string l;
        getline(cin, l);
        istringstream is(l);
        int lf, rg, v;
        is >> lf >> rg;
        if (is >> v) {
            if (rg < lf) {
                sg.relative_update(0, rg, v);
                sg.relative_update(lf, n - 1, v);
            } else {
                sg.relative_update(lf, rg, v);
            }
        } else {
            ll val = LONG_LONG_MAX;

            if (rg < lf) {
                val = min(val, sg.query(0, rg));
                val = min(val, sg.query(lf, n - 1));
            } else {
                val = min(val, sg.query(lf, rg));
            }

            cout << val << endl;
        }
    }

    return 0;
}
