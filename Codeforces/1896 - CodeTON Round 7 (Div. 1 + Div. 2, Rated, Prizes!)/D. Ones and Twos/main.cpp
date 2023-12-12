// ﷽
// https://codeforces.com/contest/1896/problem/D

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

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
    int n, q;
    cin >> n >> q;
    int a[n];
    Segtree<Sum<int>> sg(n);
    set<int> ind[3];
    for (int i = 0; i < n; i++) cin >> a[i], sg.update(i, a[i]), ind[a[i]].insert(i);

    auto search_forward = [&](int i, int x, int y) -> bool {
        if (i >= n) return x == 0 || y == 0;
        int s = i, e = n;
        while (e - s > 1) {
            int m = (s + e) / 2;
            if (sg.query(i, m) >= x) e = m;
            else s = m;
        }
        debug("forward", i, s, x, y, sg.query(i, s));
        return x == 0 || y == 0 || sg.query(i, s) == y || s + 1 < n && sg.query(i, s + 1) == x;
    };

    auto search_backward = [&](int i, int x, int y) -> bool {
        if (i < 0) return x == 0 || y == 0;
        int s = -1, e = i;
        while (e - s > 1) {
            int m = (s + e) / 2;
            if (sg.query(m, i) >= x) s = m;
            else e = m;
        }
        debug("backward", e, i, x, y, sg.query(e, i));
        return x == 0 || y == 0 || sg.query(e, i) == y || e - 1 >= 0 && sg.query(e - 1, i) == x;
    };

    debug(n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int s;
            cin >> s;
            bool ok = false;
            if (ind[1].size()) {
                // go forward with the first one
                int i = *ind[1].begin();
                ok |= search_forward(i + 1, s, s - 1);
                // go backward with the last one
                i = *prev(ind[1].end());
                ok |= search_backward(i - 1, s, s - 1);
            }
            if (ind[2].size()) {
                // go forward with the first two
                int i = *ind[2].begin();
                ok |= search_forward(i + 1, s, s - 2);
            }
            cout << (ok ? "YES" : "NO") << endl;
        } else {
            int i, v;
            cin >> i >> v, i--;
            ind[a[i]].erase(i);
            a[i] = v;
            ind[a[i]].insert(i);
            sg.update(i, a[i]);
        }
    }
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
