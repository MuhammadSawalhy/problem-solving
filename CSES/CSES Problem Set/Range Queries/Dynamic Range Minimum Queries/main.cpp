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

// source: https://codeforces.com/blog/entry/18051
template<typename T = long long, T DEFAULT = T(1e18)>
struct Segtree {
    int n = 0;
    vector<T> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    inline T merge(const T &a, const T &b) { return min(a, b); }

    void build() {
        for (int i = n - 1; i > 0; i--)
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = merge(tree[i], tree[i ^ 1]);
    }

    auto query(int l, int r) {
        T resl = DEFAULT, resr = resl;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = merge(resl, tree[l++]);
            if (r & 1) resr = merge(tree[--r], resr);
        }
        return merge(resl, resr);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q, t, a, b;
    cin >> n >> q;
    Segtree<int> sg(n + 1);

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
