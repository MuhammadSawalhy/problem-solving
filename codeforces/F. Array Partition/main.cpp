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

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

template<typename T>
struct min_segtree {
    int n;
    vector<T> tree;

    min_segtree(int n) : n(n) {
        tree.assign(n * 2, 1e18);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = min(tree[i], tree[i ^ 1]);
    }

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
            tree[i >> 1] = min(tree[i], tree[i ^ 1]);
    }

    T query(int l, int r) {
        T res = 1e18;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, tree[l++]);
            if (r & 1) res = min(res, tree[--r]);
        }
        return res;
    }

    int lower_bound(int i, T val) {
        // non-increasing
        int s = i - 1, e = n;
        while (e - s > 1) {
            int mid = (s + e) / 2;
            if (query(i, mid) <= val)
                e = mid;
            else
                s = mid;
        }
        return e;
    }
};

template<typename T>
struct max_segtree {
    int n;
    vector<T> tree;

    max_segtree(int n) : n(n) {
        tree.assign(n * 2, -1e18);
    }

    void build() {
        for (int i = n - 1; i > 0; --i)
            tree[i] = max(tree[i << 1], tree[i << 1 | 1]);
    }

    void update(int i, T val) {
        for (tree[i += n] = val; i > 1; i >>= 1)
            tree[i >> 1] = max(tree[i], tree[i ^ 1]);
    }

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
            tree[i >> 1] = max(tree[i], tree[i ^ 1]);
    }

    T query(int l, int r) {
        T res = -1e18;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, tree[l++]);
            if (r & 1) res = max(res, tree[--r]);
        }
        return res;
    }

    int rlower_bound(T val) {
        // non-increasing
        int s = -1, e = n;
        while (e - s > 1) {
            int mid = (s + e) / 2;
            if (query(mid, n - 1) < val)
                e = mid;
            else
                s = mid;
        }
        return e;
    }
};

void solve() {
    int n;
    cin >> n;
    min_segtree<ll> mn(n);
    max_segtree<ll> mx(n);

    for (int i = 0, a; i < n; i++) {
        cin >> a;
        mn.update(i, a);
        mx.update(i, a);
    }

    debug(n);
    for (int x = 0; x < n - 2; x++) {
        ll val = mx.query(0, x);

        int r = mn.lower_bound(x + 1, val);
        int e = mn.lower_bound(x + 1, val - 1);
        if (e == n) e -= 2; // keep space for 
        else e -= 1;

        debug(x, r, e);
        int j = mx.rlower_bound(val + 1);
        int q = mx.rlower_bound(val);
        q--;

        if (r > e || j > q || mn.query(x + 1, r) != val || mx.query(q, n - 1) != val) continue;

        // y -> [r, e]
        // z -> [j, q]

        debug(x, r, e, j, q);
        int y = max(r, j - 1);
        if (y < r || y > e || y + 1 < j || y + 1 > q) y = min(e, q - 1);
        if (y < r || y > e || y + 1 < j || y + 1 > q) continue;

        cout << "YES" << endl;
        cout << x + 1 << " " << y - x << " " << n - y - 1 << endl;
        return;
    }
    
    cout << "NO" << endl;
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
