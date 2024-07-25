// ﷽
// https://codeforces.com/contest/1988/problem/E

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

    Segtree() {}
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

    Segtree(const vector<long long> &values) : Segtree(values.size()) {
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

    int bs(int i, int l, int r, int val) {
        push(i);
        if (tree[i].r < l || r < tree[i].l) return -1; // outside
        if (l <= tree[i].l && tree[i].r <= r) { // the range is inside
            if (tree[i].value.mn > val) return -1;
        }
        if (tree[i].l == tree[i].r) return tree[i].l;
        int R = bs(i << 1 | 1, l, r, val);
        if (~R) return R;
        return bs(i << 1, l, r, val);
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

vector<pair<int, int>> doit(const vector<int> &a) {
    int n = sz(a);
    vector<pair<int, int>> ans(n);
    Segtree sg(a);

    for (int i = 0; i < n; i++) {
        debug(a[i]);
        ans[i].first = sg.bs(1, 0, i - 1, a[i]);
        if (ans[i].first == -1) {
            ans[i].second = -2;
            continue;
        }
        ans[i].second = sg.bs(1, 0, ans[i].first - 1, a[i]);
    }

    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Segtree delta(n);

    auto l = doit(a);
    reverse(all(a));
    auto r = doit(a);

    for (auto &[x, y]: r) {
        x = n - 1 - x;
        y = n - 1 - y;
    }

    reverse(all(a));
    reverse(all(r));

    debug(a);
    debug(l);
    debug(r);
    long long tot = 0;

    for (int i = 0; i < n; i++) {
        int R = (r[i].first - i);
        int L = (i - l[i].first);
        tot += 1LL * L * R * a[i];
        delta.update(i, i, Update(-1LL * L * R * a[i], Update::relative));
        // remove my contribution to whom extends to me
        if (i + 1 <= r[i].first - 1)
            delta.update(i + 1, r[i].first - 1, Update(-1LL * L * a[i], Update::relative));
        if (l[i].first + 1 <= i - 1)
            delta.update(l[i].first + 1, i - 1, Update(-1LL * R * a[i], Update::relative));
        // extend who I'm the first to his right or left
        int delL = l[i].first - l[i].second - 1;
        int delR = r[i].second - r[i].first - 1;
        if (l[i].first > -1)
            delta.update(l[i].first, Update(+1LL * delL * R * a[i], Update::relative));
        if (r[i].first < n)
            delta.update(r[i].first, Update(+1LL * L * delR * a[i], Update::relative));
    }

    for (int i = 0; i < n; i++) {
        cout << tot + delta.query(i, i).sum << " \n"[i == n - 1];
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
