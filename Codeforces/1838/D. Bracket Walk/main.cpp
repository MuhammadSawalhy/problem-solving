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
using ValueType = ll;

int n;

struct MinNode {
    ValueType mn = 1e18;
    ll relative_update = 0;

    MinNode() = default;
    MinNode(ValueType value) { update(value); };

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void propagate(int node, vector<MinNode> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        relupdate();
        if (left < sz) tree[left].relative_update += relative_update;
        if (right < sz) tree[right].relative_update += relative_update;
        relative_update = 0;
    }

    void update(const ValueType &val) {
        mn = val;
    }

    void relupdate() {
        mn += relative_update;
    }

    MinNode operator+(const MinNode &other) const {
        MinNode ans = *this;
        ans.mn = min(ans.mn, other.mn);
        return ans;
    }
};

struct MaxNode {
    ValueType mx = -1e18;
    ll relative_update = 0;

    MaxNode() = default;
    MaxNode(ValueType value) { update(value); };

    int count_children(int node, int tree_size) const {
        return 1 << (31 - __builtin_clz(tree_size / (node + 1)));
    }

    void propagate(int node, vector<MaxNode> &tree) {
        int left = node << 1, right = node << 1 | 1;
        int sz = tree.size();

        relupdate();
        if (left < sz) tree[left].relative_update += relative_update;
        if (right < sz) tree[right].relative_update += relative_update;
        relative_update = 0;
    }

    void update(const ValueType &val) {
        mx = val;
        relative_update = 0;
    }

    void relupdate() {
        mx += relative_update;
    }

    MaxNode operator+(const MaxNode &other) const {
        MaxNode ans = *this;
        ans.mx = max(ans.mx, other.mx);
        return ans;
    }
};


template<typename Node>
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


int32_t main() {
    ios_base::sync_with_stdio(false);

    int q;
    cin >> n >> q;

    string s;
    cin >> s;

    segtree<MinNode> val(n);
    segtree<MaxNode> inc(n), dec(n);

    inc.update(0, 0);
    dec.update(0, 0);

    int curval = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') curval++;
        else curval--;
        val.update(i, curval);

        if (i > 0 && s[i] == s[i - 1] && s[i] == '(') {
            inc.update(i, 1);
        } else {
            inc.update(i, 0);
        }
        if (i > 0 && s[i] == s[i - 1] && s[i] == ')') {
            dec.update(i, 1);
        } else {
            dec.update(i, 0);
        }
    }

    auto update = [&](int i, char c) {
        if (c == s[i]) return;
        s[i] = c;
        if (s[i] == ')')
            val.relative_update(i, n - 1, -2);
        else
            val.relative_update(i, n - 1, +2);

        if (i > 0 && s[i] == s[i - 1] && s[i] == '(') {
            inc.update(i, 1);
        } else {
            inc.update(i, 0);
        }

        if (i + 1 < n && s[i] == s[i + 1] && s[i] == '(') {
            inc.update(i + 1, 1);
        } else {
            inc.update(i + 1, 0);
        }


        if (i > 0 && s[i] == s[i - 1] && s[i] == ')') {
            dec.update(i, 1);
        } else {
            dec.update(i, 0);
        }

        if (i + 1 < n && s[i] == s[i + 1] && s[i] == ')') {
            dec.update(i + 1, 1);
        } else {
            dec.update(i + 1, 0);
        }
    };

    auto get_leftmost = [&]() {
        int s = -1, e = n - 1;
        if (val.query(0, n - 1).mn >= 0) return -1;

        while (e - s > 1) {
            int mid = (s + e) / 2;
            auto V = val.query(0, mid);
            if (V.mn >= 0) {
                s = mid;
            } else {
                e = mid;
            }
        }

        return e;
    };

    auto get_rightmost = [&]() {
        int s = -1, e = n - 1;
        int v = val.query(n - 1, n - 1).mn;

        while (e - s > 1) {
            int mid = (s + e) / 2;
            auto V = val.query(mid, n - 1);
            if (V.mn >= v) {
                e = mid;
            } else {
                s = mid;
            }
        }

        return e;
    };

    while (q--) {
        int i;
        cin >> i;
        i--;
        char c = ')';
        if (s[i] == ')') c = '(';
        update(i, c);

        if (abs(val.query(n - 1, n - 1).mn) % 2 == 1) {
            cout << "NO\n";
            continue;
        }

        int L, R;
        L = get_leftmost(), R = get_rightmost();

        bool ok = true;
        if (L != -1) {
            ok &= inc.query(0, L).mx == 1;
        }

        ok &= val.query(0, n - 1).mn == val.query(n - 1, n - 1).mn || dec.query(R, n - 1).mx == 1;

        if (ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
