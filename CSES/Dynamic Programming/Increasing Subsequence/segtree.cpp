// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

template<typename T = long long>
struct Max {
    T value;
    Max(T value = 0) : value(value) {}
    Max &operator+=(const Max &other) { return value = max(value, other.value), *this; }
    Max operator+(const Max &other) const { return Max(max(value, other.value)); }
};

// source: https://codeforces.com/blog/entry/18051
template<typename T>
struct Segtree {
    int n;
    vector<T> tree;

    Segtree() = default;
    Segtree(int n) : n(n) {
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

    void relative_update(int i, T val) {
        for (tree[i += n] += val; i > 1; i >>= 1)
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    ll x[n], a[n];
    for (int i = 0; i < n; i++) cin >> x[i], a[i] = x[i];

    sort(a, a + n);
    map<int, int> compressed;

    for (int i = 0; i < n; i++) {
        if (compressed.count(a[i])) continue;
        compressed[a[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        x[i] = compressed[x[i]];
    }

    int ans = 0;
    Segtree<Max<ll>> sg(n + 1);

    for (int i = 0; i < n; i++) {
        int val = sg.query(0, x[i] - 1) + 1;
        sg.update(x[i], val);
        ans = max(ans, val);
    }

    cout << ans;

    return 0;
}
