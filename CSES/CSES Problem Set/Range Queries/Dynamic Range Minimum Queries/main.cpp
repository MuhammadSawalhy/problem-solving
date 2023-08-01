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

const int inf = 1e9 + 1;

template<typename T>
struct segtree {
    int n;
    vector<T> tree;

    segtree(int n) : n(n) {
        tree.assign(n * 2, inf);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = min(tree[i], tree[i ^ 1]);
    }

    T query(int l, int r) {
        T res = inf;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q, t, a, b;
    cin >> n >> q;
    segtree<int> sg(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> sg.tree[i + n + 1];
    }

    sg.build();

    while (q--) {
        cin >> t >> a >> b;
        if (t == 1) {
            sg.update(a, b);
        } else {
            cout << sg.query(a, b) << endl;
        }
    }

    return 0;
}
