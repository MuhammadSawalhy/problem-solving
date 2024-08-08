// ﷽
// https://codeforces.com/contest/1997/problem/E

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

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    vector<int> vals;
    Value() = default;
    Value(ll value) { vals = {value}; }

    Value &operator+=(const Value &other) {
        vector<int> n;
        merge(vals.begin(), vals.end(), other.vals.begin(), other.vals.end(),
              back_inserter(n));
        vals = n;
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    int value;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(int value, State state = forced) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            value += other.value; // NOTE: merge updates
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        // if (state == forced) other = value;
        // else other += value;
        // other.sum += value.sum * (cnt - 1);
    }

    Update get(const Node &node) const { return *this; }
};

struct Node {
    int l = -1, r = -1; // [l, r]
    Update up;
    Value value;

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r), value(value){};

    void update(const Update &up) { this->up += up; }

    void apply_update() {
        up.apply_on(value, r - l + 1);
        up.state = Update::idle;
    }
};

struct Segtree {
    int n;
    vector<Node> tree;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node());
        for (int i = n; i < n << 1; i++)
            tree[i].l = tree[i].r = i - n;
        for (int i = n - 1; i > 0; i--)
            tree[i].l = tree[i << 1].l, tree[i].r = tree[i << 1 | 1].r;
    }

    Segtree(const vector<Value> &values) : Segtree(values.size()) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[i + n].value = values[i];
        build();
    }

    void build() {
        for (int i = n - 1; i > 0; --i) pull(i);
    }

    inline Value query(int i) { return query(1, i, i); }
    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, const Update &val) { update(1, i, i, val); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

    pair<int, int> get_it(int i, int l, int r, int level, int cnt) {
        // find up to "cnt" items which are >= level in the range [l, r];
        if (tree[i].r < l || r < tree[i].l) return {0, tree[i].r}; // default

        if (l <= tree[i].l && tree[i].r <= r) {
            // get all
            // if the count > cnt go the answer from the left
            // if <=, return directly
            const auto &vals = tree[i].value.vals;
            int cur = vals.end() - lower_bound(all(vals), level);

            if (cur < cnt || tree[i].l == tree[i].r)
                return {cur, tree[i].r};
        }

        auto left = get_it(i << 1, l, r, level, cnt);
        if (left.first == cnt) return left;
        auto right = get_it(i << 1 | 1, l, r, level, cnt - left.first);
        return {right.first + left.first, right.second};
    }

private:
    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        if (tree[i].up.state != Update::idle) {
            if (i < n) {
                int l = i << 1, r = i << 1 | 1;
                tree[l].update(tree[i].up.get(tree[l]));
                tree[r].update(tree[i].up.get(tree[r]));
            }
            tree[i].apply_update();
        }
    }

    Value query(int i, int l, int r) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value(); // default
        if (l <= tree[i].l && tree[i].r <= r) return tree[i].value;
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Update &up) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].update(up);
            push(i); // to apply the update
            return;
        }
        update(i << 1, l, r, up.get(tree[i << 1]));
        update(i << 1 | 1, l, r, up.get(tree[i << 1 | 1]));
        pull(i);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<vector<pair<int, int>>> v(n + 1);

    Segtree sg(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sg.tree[i + sg.n].value = a[i];
    }

    sg.build();

    for (int i = 0; i < q; i++) {
        int j, x;
        cin >> j >> x;
        v[x].push_back({j - 1, i});
    }

    vector<bool> ans(q);

    debug(a);
    for (int x = 1; x <= n; x++) {
        sort(rall(v[x]));
        // get groups

        vector<int> groups;
        groups.push_back(-1);
        int level = 1;
        int i = 0;

        debug(x);
        while (i < n) {
            auto b = sg.get_it(1, i, n - 1, level, x);
            debug(i, b, level);
            groups.push_back(b.second);
            i = b.second + 1;
            level++;
        }
        debug(groups);

        // ans queries

        level = 1;
        for (int i = 1; i < sz(groups); i++) {
            int l = groups[i - 1] + 1, r = groups[i];
            while (v[x].size()) {
                auto [j, q] = v[x].back();
                if (j > r) break;
                v[x].pop_back();
                if (a[j] >= level) ans[q] = true;
            }
            level++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
