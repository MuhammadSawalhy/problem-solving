// ﷽
// https://cses.fi/problemset/task/2416
// CSES -> CSES Problem Set -> Increasing Array Queries

#include <bits/stdc++.h>
#include <limits>
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
#define rall(v) v.rbegin(), v.rend()

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    vector<int> a(n), ps(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ps[i + 1] = ps[i] + a[i];
    }

    vector<int> ans(q);
    vector<array<int, 3>> queries;
    vector<pair<int, int>> v;

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        queries.push_back({a, b, i});
    }

    sort(all(queries));

    Segtree<Sum<int>> ops(n);
    v.push_back({n, 1e9 + 9});

    for (int i = n - 1; i >= 0; i--) {
        // v is strictly decreasing, in both first and second of the pair
        while (!v.empty() && v.back().second <= a[i]) {
            ops.update(v.back().first, 0);
            v.pop_back();
        }

        ops.update(i, a[i] * (v.back().first - 1 - i) - ps[v.back().first] + ps[i + 1]);
        v.emplace_back(i, a[i]);

        while (queries.size() && queries.back()[0] == i) {
            // binary search in v to get the boundary of the query
            // then get the last part of the query [v[j].second + 1, b]
            auto [A, B, k] = queries.back();
            int J = lower_bound(all(v),
                                pair<int, int>{B, 1e9 + 1},
                                greater<pair<int, int>>()) -
                    v.begin();
            int j = v[J].first;
            debug(A,B,k,j);
            if (j > i) ans[k] = ops.query(i, j - 1);
            ans[k] += a[j] * (B - j) - ps[B + 1] + ps[j + 1];
            queries.pop_back();
        }
    }

    for (auto x: ans) {
        cout << x << "\n";
    }

    return 0;
}
