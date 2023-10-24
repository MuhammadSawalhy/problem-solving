// ﷽
// https://codeforces.com/contest/1881/problem/G

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
#define int long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    long long sum = 0, mn = 1e18, mx = -1e18;
    Value() = default;
    Value(ll value) { sum = mn = mx = value; }

    Value &operator+=(const Value &other) {
        sum += other.sum;
        mn = min(mn, other.mn);
        mx = max(mx, other.mx);
        return *this;
    }

    Value operator+(const Value &other) const {
        return Value(*this) += other;
    }
};

struct Update {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    Value value;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Update() = default;
    Update(Value value, State state = forced) : value(value), state(state){};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == forced) {
            *this = other;
        } else {
            assert(other.state == relative);
            value += other.value;
        }
        return *this;
    }

    void apply_on(Value &other, int cnt) const {
        if (state == forced) other = value;
        else other += value;
        other.sum += value.sum * (cnt - 1);
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

    inline Value query(int i) { return assert(i >= 0 && i < n), query(1, i, i); }
    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, const Update &val) { update(1, i, i, val); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

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

template<typename T = long long>
struct Sum {
    T value;
    Sum(T value = 0) : value(value) {}
    Sum &operator+=(const Sum &other) { return value += other.value, *this; }
    Sum operator+(const Sum &other) const { return value + other.value; }
};

template<typename T = long long>
struct Max {
    T value;
    Max(T value = numeric_limits<T>::min() / 2) : value(value) {}
    Max &operator+=(const Max &other) { return value = max(value, other.value), *this; }
    Max operator+(const Max &other) const { return Max(max(value, other.value)); }
};

template<typename T = long long>
struct Min {
    T value;
    Min(T value = numeric_limits<T>::max() / 2) : value(value) {}
    Min &operator+=(const Min &other) { return value = min(value, other.value), *this; }
    Min operator+(const Min &other) const { return Min(min(value, other.value)); }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct Segtree2 {
    int n;
    vector<T> tree;

    Segtree2() = default;
    Segtree2(int n) : n(n) {
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

    auto query(int l, int r) {
        T res;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res.value;
    }
};


void solve() {
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    Segtree sg(n);
    Segtree2<Min<int>> mn(n);

    for (int i = 0; i < n; i++) {
        sg.update(i, Value(s[i] - 'a'));
    }

    for (int i = 0; i + 1 < n; i++) {
        if (s[i] == s[i + 1]) mn.update(i, 2);
        else if (i + 2 < n && s[i] == s[i + 2]) mn.update(i, 3);
    }

    debug(s);
    while (m--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l--, r--;
            sg.update(l, r, Update(Value(v), Update::relative));

            int lv_ = l > 0 ? sg.query(l - 1).sum % 26 : -1;
            int lv__ = l > 1 ? sg.query(l - 2).sum % 26 : -1;
            int lv = sg.query(l).sum % 26;
            int lv1 = l + 1 < n ? sg.query(l + 1).sum % 26 : -1;

            int rv_ = r > 0 ? sg.query(r - 1).sum % 26 : -1;
            int rv = sg.query(r).sum % 26;
            int rv1 = r + 1 < n ? sg.query(r + 1).sum % 26 : -1;
            int rv2 = r + 2 < n ? sg.query(r + 2).sum % 26 : -1;

            // l - 2
            if (~lv__ && lv__ == lv_)
                mn.update(l - 2, 2);
            else if (~lv__ && lv__ == lv)
                mn.update(l - 2, 3);
            else if (~lv__)
                mn.update(l - 2, 1e9);

            // l - 1
            if (~lv_ && lv_ == lv)
                mn.update(l - 1, 2);
            else if (~lv_ && ~lv1 && lv_ == lv1)
                mn.update(l - 1, 3);
            else if (~lv_)
                mn.update(l - 1, 1e9);

            // r
            if (~rv && ~rv1 && rv == rv1)
                mn.update(r, 2);
            else if (~rv && ~rv2 && rv == rv2)
                mn.update(r, 3);
            else if (~rv)
                mn.update(r, 1e9);

            // r - 1
            if (~rv_ && ~rv && rv_ == rv)
                mn.update(r - 1, 2);
            else if (~rv_ && ~rv1 && rv_ == rv1)
                mn.update(r - 1, 3);
            else if (~rv_)
                mn.update(r - 1, 1e9);

        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            debug(l, r);
            if (r - 1 >= l)
                debug(mn.query(l, r - 1));
            if (r - 2 >= l)
                debug(mn.query(l, r - 2));
            if (l == r) {
                cout << "YES\n";
                continue;
            }
            if (mn.query(l, r - 1) == 2 || r - 2 >= l && mn.query(l, r - 2) == 3)
                cout << "NO" << '\n';
            else
                cout << "YES" << '\n';
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
