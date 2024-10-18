// ﷽
// https://cses.fi/problemset/task/2420

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

constexpr int H = 2;
typedef array<long long, H> val;
vector<val> B;
const val M = {
        1000000007,
        1444444447,
        // 998244353,
        // 1000000009,
};

val tmp;

val operator*(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = a[i] * b[i] % M[i];
    return tmp;
}

val operator-(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] - b[i] + M[i]) % M[i];
    return tmp;
}

val operator+(const val &a, const val &b) {
    for (int i = 0; i < H; i++) tmp[i] = (a[i] + b[i]) % M[i];
    return tmp;
}

val getval(int x) {
    for (int i = 0; i < H; i++) tmp[i] = x % M[i];
    return tmp;
}

void setB(int n) {
    if (B.size() == 0) {
        mt19937 rng(random_device{}());
        B.assign(2, getval(1));
        for (int i = 0; i < H; i++)
            B.back()[i] = uniform_int_distribution<ll>(1, M[i] - 1)(rng);
    }
    while ((int) B.size() <= n) B.push_back(B.back() * B[1]);
}

// source: https://codeforces.com/blog/entry/18051
struct Segtree {
    val DEFAULT = getval(0);
    int n = 0;
    vector<val> tree;
    vector<ll> cnt;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT), cnt.assign(n * 2, 0); }

    val merge(const val &a, ll acnt, const val &b, ll bcnt) {
        return a * B[bcnt] + b;
    }

    void build() {
        for (int i = n; i < 2 * n; i++) cnt[i] = 1;
        for (int i = n - 1; i > 0; i--) {
            cnt[i] = cnt[i << 1] + cnt[i << 1 | 1];
            tree[i] = merge(tree[i << 1], cnt[i << 1], tree[i << 1 | 1], cnt[i << 1 | 1]);
        }
    }

    void update(int i, const val &val) {
        for (tree[i += n] = val; i >>= 1;)
            tree[i] = merge(tree[i << 1], cnt[i << 1], tree[i << 1 | 1], cnt[i << 1 | 1]);
    }

    auto query(int l, int r) {
        val resl = DEFAULT, resr = resl;
        ll lcnt = 0, rcnt = 0;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) resl = merge(resl, lcnt, tree[l], cnt[l]), lcnt += cnt[l], l++;
            if (r & 1) r--, resr = merge(tree[r], cnt[r], resr, rcnt), rcnt += cnt[r];
        }
        return merge(resl, lcnt, resr, rcnt);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    Segtree sg1(n);
    Segtree sg2(n);

    for (int i = 0; i < n; i++) {
        sg1.tree[i + n] = getval(s[i] - 'a' + 1);
        sg2.tree[(n - i - 1) + n] = getval(s[i] - 'a' + 1);
    }

    sg1.build();
    sg2.build();

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            char c;
            cin >> i >> c, i--;
            sg1.update(i, getval(c - 'a' + 1));
            sg2.update(n - i - 1, getval(c - 'a' + 1));
        } else {
            int l, r;
            cin >> l >> r, l--, r--;
            auto q1 = sg1.query(l, r);
            auto q2 = sg2.query(n - r - 1, n - l - 1);
            cout << (q1 == q2 ? "YES" : "NO") << endl;
        }
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    setB(3e5);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        debug("--------", t);
        solve();
    }

    return 0;
}
