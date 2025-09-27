#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

// source: https://codeforces.com/blog/entry/18051
struct Segtree {
    constexpr static ll DEFAULT = 0;
    inline ll merge(const ll &a, const ll &b) { return a + b; }

    int n = 0;
    vector<ll> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    void pull(int i) { tree[i] = merge(tree[i << 1], tree[i << 1 | 1]); }

    void build() {
        for (int i = n - 1; i > 0; i--) pull(i);
    }

    void update(int i, ll val) {
        for (tree[i += n] = val; i > 1; i >>= 1) pull(i >> 1);
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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    stack<int> st;
    // next >=
    vector<int> next_ge(n + 1, n);
    for (int i = 0; i < n; i++) {
        while (st.size() && a[st.top()] <= a[i]) {
            next_ge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // next >
    st = stack<int>();
    vector<int> next_gt(n + 1, n);
    for (int i = 0; i < n; i++) {
        while (st.size() && a[st.top()] < a[i]) {
            next_gt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // prev >
    st = stack<int>();
    vector<int> prev_gt(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && a[st.top()] < a[i]) {
            prev_gt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // next min
    st = stack<int>();
    vector<int> next_lt(n + 1, n);
    for (int i = 0; i < n; i++) {
        while (st.size() && a[st.top()] > a[i]) {
            next_lt[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // prev <=
    st = stack<int>();
    vector<int> prev_le(n + 1, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (st.size() && a[st.top()] >= a[i]) {
            prev_le[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    int ans = 0;

    vector<int> ind[n + 1];
    for (int i = 0; i < n; i++) ind[a[i]].push_back(i);

    Segtree sg(n + 1);

    for (int x = 1; x <= n; x++) {
        int y = k - x;
        if (y <= 0 || y > n) continue;
        for (auto i: ind[y]) {
            sg.update(i, next_ge[i] - i);
        }
        for (auto i: ind[x]) {
            int cnt = i - prev_le[i];
            int r = next_lt[i] - 1;
            int total = sg.query(i + 1, r + 1);
            int partial = 0;
            auto j = upper_bound(all(ind[y]), r + 1) - ind[y].begin();
            if (j < ind[y].size()) {
                j = ind[y][j];
                if (prev_gt[j] <= r) {
                    partial = next_gt[j] - j;
                }
            }
            ans += cnt * (total + partial);
        }
        for (auto i: ind[y]) {
            sg.update(i, 0);
        }
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}
