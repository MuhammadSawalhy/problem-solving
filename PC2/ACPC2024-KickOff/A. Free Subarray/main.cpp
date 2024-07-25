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

int32_t main() {
    // if all ones, can't take (1, n)
    // if all ones and not (1, n) ignore the bit
    //
    // if only one 0 exists, should take all
    // if

    int n;
    cin >> n;
    int a[n];
    int zeros[30][n + 1];
    int lst[30];

    Segtree<Max<int>> sg(n);

    for (int b = 0; b < 30; b++) lst[b] = -1, zeros[b][0] = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int b = 0; b < 30; b++) {
            zeros[b][i + 1] = zeros[b][i] + (a[i] >> b & 1 ^ 1);
        }
    }

    for (int i = 0; i < n; i++) {
        int l = i;
        for (int b = 0; b < 30; b++) {
            if (a[i] >> b & 1 ^ 1) {
                lst[b] = i;
            }
            if (lst[b] != -1)
                minit(l, lst[b]);
        }

        bool ok = true;

        debug(i, l);
        for (int b = 0; b < 30; b++) {
            int zl = zeros[b][l];
            int zr = zeros[b][n] - zeros[b][i + 1];
            int z = zeros[b][i + 1] - zeros[b][l];
            debug(b, zl, z, zr);

            bool ALL = i == n - 1 && l == 0;
            if (z == 0 && zl == 0 && zr == 0 && ALL) {
                ok = false;
            }

            if (z && zl == 0 && zr == 0 && !ALL) {
                ok = false;
            }

            if ((zl + zr) && !z) {
                ok = false;
            }
        }
        debug(ok);

        if (ok) sg.update(i, l);
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int val = sg.query(l, r);
        debug(l, r, val);
        if (val >= l) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
