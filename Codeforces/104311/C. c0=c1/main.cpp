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

set<int> calc(vector<int> &a, int x, int y) {
    int n = a.size();
    int mn = 1e9, mx = -1e9;
    set<int> ans;

    segtree sg(n);
    for (int i = 0; i < n; i++) {
        sg.update(i, 0);
    }

    for (int i = 0; i < n; i++) {
        sg.relative_update(0, i, a[i]);
        if (i + 1 >= x) {
            auto q = sg.query(i - y + 1, i - x + 1);
            mn = min(mn, q.mn);
            mx = max(mx, q.mx);
            if (x == y)
                ans.insert(q.mn);
        }
    }

    if (x == y) return ans;
    for (int i = mn; i <= mx; i++) ans.insert(i);
    return ans;
}

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = a[i] * 2 - 1;
    for (int i = 0; i < n; i++) cin >> b[i], b[i] = 1 - b[i] * 2;

    auto A = calc(a, x1, y1);
    auto B = calc(b, x2, y2);

    for (auto aa: A) {
        if (B.count(aa)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
