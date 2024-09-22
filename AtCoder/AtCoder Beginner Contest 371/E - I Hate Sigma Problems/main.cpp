// ﷽
// https://atcoder.jp/contests/abc371/tasks/abc371_e

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

// source: https://codeforces.com/blog/entry/18051
template<typename T = long long, T DEFAULT = 0>
struct Segtree {
    int n = 0;
    vector<T> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    inline T merge(const T &a, const T &b) { return a + b; }

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vvi ind(n + 1);

    Segtree sg(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        reverse(all(ind[i]));
        if (ind[i].size())
            sg.update(ind[i].back(), n - ind[i].back()), ind[i].pop_back();
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sg.query(i, n - 1);

        if (ind[a[i]].size()) {
            sg.update(ind[a[i]].back(), n - ind[a[i]].back());
            ind[a[i]].pop_back();
        }
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    while (t--)
        solve();

    return 0;
}
