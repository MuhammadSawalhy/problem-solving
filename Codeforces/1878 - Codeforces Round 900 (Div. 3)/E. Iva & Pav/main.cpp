// بسم الله الرحمن الرحيم
// https://codeforces.com/contest/1878/problem/E
// Codeforces -> Codeforces Round 900 (Div. 3) -> E. Iva & Pav

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

template<typename T = long long>
struct And {
    T value;
    And(T value = -1) : value(value) {}
    And &operator+=(const And &other) { return value = value & other.value, *this; }
    And operator+(const And &other) const { return And(value & other.value); }
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
    int n;
    cin >> n;

    Segtree<And<int>> sg(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sg.update(i, x);
    }

    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;
        int s = l - 1, e = n;
        int r = -2;
        while (e - s > 1) {
            int mid = (s + e) / 2;
            if (sg.query(l, mid) >= k) {
                s = mid;
                r = mid;
            } else {
                e = mid;
            }
        }

        cout << r + 1 << ' ';
    }

    cout << endl;
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
