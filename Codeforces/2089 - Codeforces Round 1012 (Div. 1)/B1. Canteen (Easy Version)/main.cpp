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
    constexpr static ll DEFAULT = -1e18;
    int n = 0;
    vector<ll> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    inline ll merge(const ll &a, const ll &b) { return max(a, b); }

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
    vector<int> a(n * 2 + 2), psa(n * 2 + 2);
    vector<int> b(n * 2 + 2), psb(n * 2 + 2);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        psa[i + 1] = psa[i] + a[i];
    }

    for (int i = n; i < n * 2; i++) {
        a[i] = a[i - n];
        psa[i + 1] = psa[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        psb[i + 1] = psb[i] + b[i];
    }

    for (int i = n; i < n * 2; i++) {
        b[i] = b[i - n];
        psb[i + 1] = psb[i] + b[i];
    }

    auto getsum = [&](const vector<int> &ps, int l, int r) {
        if (r < l) r += n;
        return ps[r + 1] - ps[l];
    };

    int ans = 1;

    Segtree sg(n * 2);

    for (int i = 0; i < n * 2; i++) {
        sg.update(i, psb[i + 1] - psa[i + 1]);
    }

    auto getmax = [&](int l, int r) {
        if (r < l) r += n;
        return sg.query(l, r);
    };

    for (int i = 0; i < n; i++) {
        int l = i - 1, r = i + n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            debug(mid);
            int prev = psb[i] - psa[i];
            if (getmax(i, mid) >= prev) r = mid;
            else l = mid;
        }
        debug(i, r);
        ans = max(ans, r - i + 1);
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        debug(t);
        solve();
    }

    return 0;
}
