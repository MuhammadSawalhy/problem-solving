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
struct Sum {
    T value;
    Sum(T value = 0) : value(value) {}
    Sum &operator+=(const Sum &other) { return value += other.value, *this; }
    Sum operator+(const Sum &other) const { return value + other.value; }
};

template<typename T = long long>
struct Max {
    T value;
    Max(T value = numeric_limits<T>::min() / 2) : value(value) {}
    Max &operator+=(const Max &other) { return value = max(value, other.value), *this; }
    Max operator+(const Max &other) const { return Max(max(value, other.value)); }
};

template<typename T = long long>
struct Min {
    T value;
    Min(T value = numeric_limits<T>::max() / 2) : value(value) {}
    Min &operator+=(const Min &other) { return value = min(value, other.value), *this; }
    Min operator+(const Min &other) const { return Min(min(value, other.value)); }
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

void solve() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> ind;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }

    int min_required[n];
    min_required[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        min_required[i] = max(a[i + 1] - a[i], min_required[i + 1]);
    }

    Segtree<Min<ll>> sg(n);
    for (int i = 0; i < n; i++) {
        sg.update(i, min_required[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        int i = ind[x];
        int j = upper_bound(a, a + n, x + k) - a - 1;
        if (sg.query(i, j) <= k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
