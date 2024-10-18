// ﷽
// https://cses.fi/problemset/task/1748

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
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

constexpr int MOD = 1e9 + 7;

// source: https://codeforces.com/blog/entry/18051
struct Segtree {
    constexpr static ll DEFAULT = 0;
    int n = 0;
    vector<ll> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    inline ll merge(const ll &a, const ll &b) { return (a + b) % MOD; }

    void pull(int i) { tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }

    void build() {
        for (int i = n - 1; i > 0; i--) pull(i);
    }

    void update(int i, ll val) {
        for (tree[i += n] = val; i >>= 1;) pull(i);
    }

    auto query(int l, int r) {
        ll resl = DEFAULT, resr = resl;
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vi b = a;
    sort(all(b));
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(all(b), a[i]) - b.begin() + 1;
    }

    debug(a);

    Segtree sg(n + 1);
    for (int i = 0; i < n; i++) {
        sg.update(a[i], (sg.query(0, a[i]) + 1) % MOD);
        debug(sg.query(a[i], a[i]));
    }

    cout << sg.query(0, n) << '\n';
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
