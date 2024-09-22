// ﷽
// https://cses.fi/problemset/task/1735
// CSES -> CSES Problem Set -> Range Updates and Sums

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

// Replaceable by primitives (using Value = long long)
struct Val {
    ll sum = 0;
    Val() = default;
    Val(ll s): sum(s) {}

    Val &operator+=(const Val &val) {
        sum += val.sum;
        return *this;
    }

    Val operator+(const Val &val) const {
        return Val(*this) += val;
    }
};

struct Upd {
    // NOTE: Sometime you need to split the update, in these cases
    // you should include the range [a, b] of the update in the struct Update
    int x;
    enum State {
        idle,
        relative,
        forced
    } state = idle;

    Upd() = default;
    Upd(int x, State state) : x(x), state(state){};

    Upd &operator+=(const Upd &up) {
        if (state == idle || up.state == forced) {
            *this = up;
        } else {
            assert(up.state == relative);
            x += up.x; // NOTE: merge updates
        }
        return *this;
    }

    void apply_on(Val &val, int cnt) const {
        if (state == forced) val = x * cnt;
        else val += x * cnt;
    }
};

struct Node {
    Val val;
    Upd up;
    Node *l = nullptr, *r = nullptr;

    Node() = default;
    Node(Node *l, Node *r) : l(l), r(r) { pull(); }
    ~Node() { delete l, delete r; }

    inline void pull() { val = l->val + r->val; }

    void push(int cnt) {
        if (cnt > 1 && !l) l = new Node(), r = new Node();
        if (up.state == Upd::idle) return;
        up.apply_on(val, cnt);
        if (l) l->up += up, r->up += up;
        up.state = Upd::idle;
    }
};

template<bool persist = false>
struct DynamicSegTree {
    static const int MIN = -1e9, MAX = 1e9;

    // ~DynamicSegTree() { delete root; }

    Node *root = new Node();

    Node *update(int l, int r, const Upd &up) {
        return root = update(l, r, up, root, MIN, MAX);
    }

    Val query(int l, int r) { return query(l, r, root, MIN, MAX); }

    Node *update(int l, int r, const Upd &up, Node *node, int L, int R) {
        if (node) node->push(R - L + 1);
        if (!node || l > R || L > r || L > R) return node;
        if (persist) node = new Node(*node);
        if (l <= L && R <= r) {
            node->up += up, node->push(R - L + 1);
            return node;
        }
        int mid = L + (R - L) / 2;
        node->l = update(l, r, up, node->l, L, mid);
        node->r = update(l, r, up, node->r, mid + 1, R);
        node->pull();
        return node;
    }

    Val query(int l, int r, Node *node, int L, int R) {
        if (!node || l > R || L > r || L > R) return Val();
        node->push(R - L + 1);
        if (l <= L && R <= r) return node->val;
        int mid = L + (R - L) / 2;
        return query(l, r, node->l, L, mid) + query(l, r, node->r, mid + 1, R);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> values(n);
    DynamicSegTree sg;
    for (int i = 0, a; i < n; i++) cin >> values[i], sg.update(i, i, Upd(values[i], Upd::forced));

    while (q--) {
        int t, a, b, x;
        cin >> t >> a >> b, a--, b--;
        if (t == 1) {
            cin >> x;
            sg.update(a, b, Upd(x, Upd::relative));
        } else if (t == 2) {
            cin >> x;
            debug(a, b, x);
            sg.update(a, b, Upd(x, Upd::forced));
        } else {
            cout << sg.query(a, b).sum << endl;
        }
    }

    return 0;
}
