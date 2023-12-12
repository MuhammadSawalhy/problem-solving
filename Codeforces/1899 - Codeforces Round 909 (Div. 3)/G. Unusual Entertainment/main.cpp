// ﷽
// https://codeforces.com/contest/1899/problem/G

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

const int N = 1e5 + 5;
int value[N], p[N], pos[N];
bool ans[N];
Segtree<Sum<int>> sg(N);
vector<array<int, 3>> queries[N];
vector<int> adj[N];

void dfs(int i, int p) {
    int Q = queries[i].size();
    int a[Q];
    for (int j = 0; j < Q; j++) {
        a[j] = sg.query(queries[i][j][0], queries[i][j][1]);
    }

    for (int j: adj[i]) {
        if (j == p) continue;
        dfs(j, i);
    }

    sg.update(pos[i], 1);

    for (int j = 0; j < Q; j++) {
        int x = sg.query(queries[i][j][0], queries[i][j][1]);
        if (x != a[j]) {
            ans[queries[i][j][2]] = 1;
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        pos[p[i] - 1] = i;
    }

    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--, x--;
        queries[x].push_back({l, r, i});
    }

    dfs(0, -1);

    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        queries[i].clear();
        sg.update(i, 0);
    }

    for (int i = 0; i < q; i++) {
        cout << (ans[i] ? "YES" : "NO") << '\n';
        ans[i] = false;
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
