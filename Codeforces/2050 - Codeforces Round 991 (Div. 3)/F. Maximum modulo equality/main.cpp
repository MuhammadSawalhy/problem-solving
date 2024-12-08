// ﷽
// https://codeforces.com/contest/2050/problem/F

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
#define vii vector<pii>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

// source: https://codeforces.com/blog/entry/18051
struct Segtree {
    constexpr static ll DEFAULT = 0;
    int n = 0;
    vector<ll> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    inline ll merge(const ll &a, const ll &b) { return gcd(a, b); }

    void pull(int i) { tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }

    void build() {
        for (int i = n - 1; i > 0; i--) pull(i);
    }

    void update(int i, ll val) {
        for (tree[i += n] = val; i > 1; i >>= 1) pull(i / 2);
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Segtree sg(n - 1);
    for (int i = 0; i < n - 1; i++) {
        b[i] = abs(a[i + 1] - a[i]);
        sg.update(i, b[i]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        if (l == r) {
            cout << "0 ";
            continue;
        }

        r--;
        cout << sg.query(l, r) << ' ';
    }
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
