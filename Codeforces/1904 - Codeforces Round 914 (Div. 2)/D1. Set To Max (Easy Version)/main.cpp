// ﷽
// https://codeforces.com/contest/1904/problem/D1

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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<int> bind[n + 1], aind[n + 1];
    Segtree<Max<int>> sg(n);

    for (int i = 1; i <= n; i++) {
        aind[i].push_back(-1);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        aind[a[i]].push_back(i);
        sg.update(i, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        aind[i].push_back(n);
    }


    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bind[b[i]].push_back(i);
    }

    set<int> ind;
    ind.insert(-1);
    ind.insert(n);
    for (int x = 1; x <= n; x++) {
        for (auto i: bind[x]) {
            if (a[i] == b[i]) continue;
            // i-th element in b
            auto it = ind.lower_bound(i);
            int j = *prev(it);
            int k = *it;

            // in [j + 1, k - 1], search in a for a possible value
            auto it2 = lower_bound(all(aind[b[i]]), i);
            int J = *prev(it2), K = *it2;

            bool ok = false;
            if (J > j) {
                int mx = sg.query(J, i);
                ok |= mx == b[i];
            }
            if (K < k) {
                int mx = sg.query(i, K);
                ok |= mx == b[i];
            }

            if (!ok) {
                cout << "NO\n";
                return;
            }
        }

        for (auto i: bind[x]) {
            ind.insert(i);
        }
    }

    cout << "YES\n";
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
