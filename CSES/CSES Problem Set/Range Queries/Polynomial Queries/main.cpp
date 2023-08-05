// ﷽
// https://cses.fi/problemset/task/1736
// CSES -> CSES Problem Set -> Polynomial Queries

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

// relative updates have to be linear
struct CustomUpdate {
    enum State {
        idle,
        relative
    };

    State state = idle;
    long long a = 0, inc = 0;

    CustomUpdate() = default;
    CustomUpdate(int a, int inc, State state = relative) : a(a), inc(inc), state(state){};

    // ACCUMULATE
    inline CustomUpdate &operator+=(const CustomUpdate &other) {
        if (state == idle) {
            a = other.a, inc = other.inc;
            state = other.state;
        } else {
            a += other.a;
            inc += other.inc;
        }
        return *this;
    }
};

template<typename Update = CustomUpdate>
struct CustomValue {
    long long sum = 0, cnt = 0;

    CustomValue() = default;
    CustomValue(ll value) { sum = value, cnt = 1; }

    // 1. trigger update
    // 2. accumulate
    // 3. split update to left and right
    // 4. apply

    // APPLY
    inline void operator+=(const Update &up) {
        sum += up.a * cnt + (cnt * (cnt - 1) / 2 * up.inc);
    }

    inline CustomValue operator+(const CustomValue &other) const {
        CustomValue ans;
        ans.sum = sum + other.sum;
        ans.cnt = cnt + other.cnt;
        return ans;
    }
};

template<typename Value, typename Update>
struct Node {
    Update up;
    Value value;
    int l = -1, r = -1; // [l, r]

    Node() = default;
    Node(int l, int r, const Value &value) : l(l), r(r) { update(value); };

    void update(const Update &up) {
        this->up += up; // accumulate updates
    }

    void apply_update() {
        this->value += up;
        up.state = Update::idle;
    }
};

template<typename Value, typename Update>
struct Segtree {
    int n;
    vector<Node<Value, Update>> tree;

    Segtree(int n) {
        if ((n & (n - 1)) != 0)
            n = 1 << (32 - __builtin_clz(n));
        this->n = n;
        tree.assign(n << 1, Node<Value, Update>());
        for (int i = n; i < n << 1; i++)
            tree[i].l = tree[i].r = i - n;
        for (int i = n - 1; i > 0; i--)
            tree[i].l = tree[i << 1].l, tree[i].r = tree[i << 1 | 1].r;
    }

    Segtree(const vector<Update> &values) : Segtree(values.size()) {
        for (int i = 0; i < (int) values.size(); i++)
            tree[i + n].update(values[i]), push(i + n);
        build();
    }

    void build() {
        for (int i = n - 1; i > 0; --i) pull(i);
    }

    inline Value query(int i) { return query(1, i, i); }
    inline Value query(int i, int j) { return query(1, i, j); }
    inline void update(int i, const Update &val) { update(1, i, i, val); }
    inline void update(int i, int j, const Update &val) { update(1, i, j, val); }

private:
    Update get_right_update(const Update &up, int cnt) {
        return Update(up.a + cnt * up.inc, up.inc);
    }

    void pull(int i) {
        tree[i].value = tree[i << 1].value + tree[i << 1 | 1].value;
    }

    void push(int i) {
        int left = i << 1, right = i << 1 | 1;
        if (tree[i].up.state != Update::idle) {
            // SPLIT
            if (i < n) tree[left].update(tree[i].up);
            if (i < n) tree[right].update(get_right_update(tree[i].up, tree[left].value.cnt));
            tree[i].apply_update();
        }
    }

    Value query(int i, int l, int r) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return Value(); // default
        if (l <= tree[i].l && tree[i].r <= r) return tree[i].value;
        return query(i << 1, l, r) + query(i << 1 | 1, l, r);
    }

    void update(int i, int l, int r, const Update &val) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return;
        if (l <= tree[i].l && tree[i].r <= r) {
            tree[i].update(val);
            push(i); // to apply the update
            return;
        }
        update(i << 1, l, r, val);
        if (tree[i << 1].r >= l) {
            update(i << 1 | 1, tree[i << 1 | 1].l, r, get_right_update(val, tree[i << 1].r - l + 1));
        } else {
            update(i << 1 | 1, l, r, val);
        }
        pull(i);
    }
};

using Update = CustomUpdate;
using Value = CustomValue<Update>;
using SegTREE = Segtree<Value, Update>;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;

    SegTREE sg(n);

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        sg.tree[i + sg.n].value = a;
    }

    sg.build();

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1) {
            // TRIGGER
            sg.update(a, b, Update(1, 1, Update::relative));
        } else {
            cout << sg.query(a, b).sum << endl;
        }
    }

    return 0;
}
