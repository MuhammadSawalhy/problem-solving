// ∩╖╜
// https://codeforces.com/contest/1179/problem/C
// Codeforces -> Codeforces Round 569 (Div. 1) -> C. Serge and Dining Room

#include <bits/stdc++.h>
using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

struct Value;
struct Update;
struct Node;

// Replaceable by primitives (using Value = long long)
struct Value {
    long long points, excess_removal;
    Value() = default;
    Value(ll points, ll er) : points(points), excess_removal(er) {}

    Value &operator+=(const Value &other) {
        int to_remove = min(points, other.excess_removal);
        points -= to_remove;
        points += other.points;
        excess_removal += other.excess_removal - to_remove;
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
        else {
            other += value;
            // points update
            int to_remove = min(other.points, other.excess_removal);
            other.points -= to_remove;
            other.excess_removal -= to_remove;
        }
    }

    Update get(Node &node) const { return *this; }
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

    int get_ans(int i, int rrem) {
        if (tree[i].value.points - rrem <= 0) return -1;
        if (tree[i].l == tree[i].r) return tree[i].l;
        int r = get_ans(i << 1 | 1, rrem);
        if (r != -1) return r;
        int l = get_ans(i << 1, rrem - min(rrem, tree[i << 1 | 1].value.points) + tree[i << 1 | 1].value.excess_removal);
        return l;
    }

private:
    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        int l = i << 1, r = i << 1 | 1;
        if (tree[i].up.state != Update::idle) {
            if (i < n) {
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a[n];
    int b[m];

    Segtree B(1e6 + 6);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        B.update(a[i], Update(Value(1, 0), Update::relative));
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
        B.update(b[i], Update(Value(0, 1), Update::relative));
    }

    int q;
    cin >> q;
    while (q--) {
        int t, i, x;
        cin >> t >> i >> x, i--;

        if (t == 1) {
            B.update(a[i], Update(Value(-1, 0), Update::relative));
            a[i] = x;
            B.update(a[i], Update(Value(+1, 0), Update::relative));
        } else if (t == 2) {
            B.update(b[i], Update(Value(0, -1), Update::relative));
            b[i] = x;
            B.update(b[i], Update(Value(0, +1), Update::relative));
        }

        cout << B.get_ans(1, 0) << '\n';
    }

    return 0;
}

