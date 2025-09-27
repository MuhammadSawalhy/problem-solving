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
#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

struct Value;
struct Update;
struct Node;

int pow42[10];

struct Value {
    int value = -1, dist = 1e18;
    bool issame = true;
    Value() = default;
    Value(ll _value) {
        value = _value;
        issame = true;
        for (int i = 1; i < 10; i++) {
            if (pow42[i] >= value) {
                dist = pow42[i] - value;
                break;
            }
        }
    }

    // make sure that: x + Value() == x
    Value &operator+=(const Value &other) {
        if (other.value == -1) return *this;
        if (value == -1) return *this = other;
        dist = min(dist, other.dist);
        issame = issame && other.issame && value == other.value;
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
        increment,
        set
    } state = idle;

    Update() = default;
    Update(int value, State state = set) : value(value), state(state) {};

    Update &operator+=(const Update &other) {
        if (state == idle || other.state == set) {
            *this = other;
        } else if (state == set) {
            assert(other.state == increment);
            value += other.value;
        } else if (state == increment) {
            value += other.value;
        } else {
            assert(false);
        }
        return *this;
    }

    static int fix(int value, int inc) {
        value += inc;
        int i = 0;
        while (pow42[i] < value) i++;
        while (pow42[i] == value) value += inc, i++;
        return value;
    }

    // updates on all leafs (node.l == node.r) are applicable
    // updates are applicable on decendant node values if it is applicable on the parent node
    inline bool is_applicable(const Value &v) const {
        return state == set || v.dist >= value || v.issame;
    }

    void apply_on(Value &v, int cnt) const {
        if (state == set) {
            v = Value(value);
        } else {
            if (v.issame) {
                v = Value(v.value + value); // to recalculate the dist
            } else {
                assert(v.dist >= value);
                v.dist -= value;
            }
        }
    }

    inline Update get(const Node &node) const { return *this; }
};

struct Node {
    int l = -1, r = -1; // [l, r]
    Update up;
    Value value;

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r), value(value) {};

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

    inline auto query(int i) { return query(1, i, i); }
    inline auto query(int i, int j) { return query(1, i, j); }
    inline auto update(int i, int j, const Update &up) { return update(1, i, j, up); }

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

    Value update(int i, int l, int r, const Update &up) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value();
        if (l <= tree[i].l && tree[i].r <= r && up.is_applicable(tree[i].value)) {
            tree[i].update(up);
            push(i); // to apply the update
            return tree[i].value;
        }
        Value result = update(i << 1, l, r, up.get(tree[i << 1])) +
                       update(i << 1 | 1, l, r, up.get(tree[i << 1 | 1]));
        pull(i);
        return result;
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    pow42[0] = 1;
    for (int i = 0; i < 9; i++) pow42[i + 1] = pow42[i] * 42;

    int n, q;
    cin >> n >> q;
    Segtree sg(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        sg.tree[sg.n + i].value = Value(x);
    }
    sg.build();

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i;
            cin >> i, i--;
            cout << sg.query(i).value << endl;
        } else if (type == 2) {
            int a, b, x;
            cin >> a >> b >> x, a--, b--;
            sg.update(a, b, Update(x, Update::set));
        } else {
            int a, b, x;
            cin >> a >> b >> x, a--, b--;
            debug(a, b, x);
            int result;
            do {
                result = sg.update(a, b, Update(x, Update::increment)).dist;
                debug(result);
            } while (result == 0);
        }
    }

    return 0;
}
