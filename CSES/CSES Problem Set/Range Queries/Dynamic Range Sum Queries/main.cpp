// ﷽
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

template<typename T = ll, bool persist = false>
struct DynamicSegTree {
    static const int MIN = -(1 << 30), MAX = (1 << 30) - 1;
    static const T DEFAULT = 0;

    static T merge(ll a, ll b) { return a + b; }

    struct Node {
        T x = DEFAULT;
        ll up = 0;
        Node *l = nullptr, *r = nullptr;

        Node() = default;
        Node(Node *l, Node *r) : l(l), r(r) { pull(); }
        ~Node() { delete l, delete r; }

        inline void pull() {
            if (l) x = merge(l->x, r->x);
        }

        inline void update(int val) { up += val; }

        void push(int cnt) {
            if (cnt > 1 && !l) l = new Node(), r = new Node();
            if (up == 0) return;
            x = merge(x, up * (cnt)); // apply update
            if (cnt > 1) l->update(up), r->update(up), up = 0;
            up = 0;
        }
    };

    // ~DynamicSegTree() { delete root; }

    Node *root = new Node();

    Node *update(int l, int r, ll up) {
        return root = update(l, r, up, root, MIN, MAX);
    }

    ll query(int l, int r) { return query(l, r, root, MIN, MAX); }

    Node *update(int l, int r, ll up, Node *node, int L, int R) {
        if (node) node->push(R - L + 1);
        if (!node || l > R || r < L || L > R) return node;
        if (persist) node = new Node(*node);
        if (l <= L && R <= r) {
            node->update(up), node->push(R - L + 1);
            debug(L, R, node->x);
            return node;
        }
        int mid = L + (R - L) / 2;
        node->l = update(l, r, up, node->l, L, mid);
        node->r = update(l, r, up, node->r, mid + 1, R);
        node->pull();
        debug(L, R, node->x);
        return node;
    }

    T query(int l, int r, Node *node, int L, int R) {
        if (!node || l > R || r < L || L > R) return DEFAULT;
        node->push(R - L + 1);
        if (l <= L && R <= r) return node->x;
        int mid = L + (R - L) / 2;
        return merge(query(l, r, node->l, L, mid), query(l, r, node->r, mid + 1, R));
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    DynamicSegTree sg;
    vector<int> v(n);

    for (int i = 0, a; i < n; i++) {
        cin >> v[i];
        sg.update(i, i, v[i]);
    }

    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        debug(t, a, b);
        if (t == 1) {
            sg.update(a - 1, a - 1, -v[a - 1] + b);
            v[a - 1] = b;
        } else {
            cout << sg.query(a - 1, b - 1) << endl;
        }
    }

    return 0;
}
