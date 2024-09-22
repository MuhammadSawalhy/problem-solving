// ﷽
// https://codeforces.com/contest/2005/problem/D

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

    inline T merge(const T &a, const T &b) { return gcd(a, b); }

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
    Segtree sga(n), sgb(n);
    /*vi suffgcda(n + 1), suffgcdb(n + 1), prefgcda(n + 1), prefgcdb(n + 1);*/

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sga.tree[i + n] = a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sgb.tree[i + n] = b[i];
    }

    sga.build();
    sgb.build();

    auto getsuffs = [&](const vi &v) {
        vector<vector<pii>> ans(n);
        ans[n - 1].push_back({v[n - 1], n - 1});

        for (int i = n - 2; i >= 0; i--) {
            ans[i].push_back({v[i], i});
            for (auto [g, j]: ans[i + 1]) {
                g = gcd(g, v[i]);
                if (ans[i].back().first != g)
                    ans[i].push_back({g, j});
            }
        }

        return ans;
    };

    auto getprefs = [&](const vi &v) {
        vector<vector<pii>> ans(n);
        ans[0].push_back({v[0], 0});

        for (int i = 1; i < n; i++) {
            ans[i].push_back({v[i], i});
            for (auto [g, j]: ans[i - 1]) {
                g = gcd(g, v[i]);
                if (ans[i].back().first != g)
                    ans[i].push_back({g, j});
            }
        }

        return ans;
    };

    auto asuffs = getsuffs(a);
    auto bsuffs = getsuffs(b);
    auto aprefs = getprefs(a);
    auto bprefs = getprefs(b);

    int ans = 0, cnt = 0;
    debug(n);
    for (int i = 0; i < n; i++) {
        vi flippoints;

        flippoints.push_back(0);
        for (auto [_, i]: aprefs[n - 1]) {
            flippoints.push_back(i);
        }

        for (auto [_, i]: bprefs[n - 1]) {
            if (i + 1 < n)
                flippoints.push_back(i);
        }

        for (auto [g, i]: asuffs[i]) {
            flippoints.push_back(i);
        }

        for (auto [g, i]: bsuffs[i]) {
            flippoints.push_back(i);
        }

        sort(all(flippoints));
        flippoints.erase(unique(all(flippoints)), flippoints.end());
        int k = 0;
        while (flippoints[k] < i) k++;
        assert(flippoints[k] == i);
        debug(i, flippoints);
        while (k < sz(flippoints)) {
            int j = flippoints[k];
            int cura = gcd(i > 0 ? sga.query(0, i - 1) : 0, sgb.query(i, j));
            cura = gcd(cura, j + 1 < n ? sga.query(j + 1, n - 1) : 0);
            int curb = gcd(i > 0 ? sgb.query(0, i - 1) : 0, sga.query(i, j));
            curb = gcd(curb, j + 1 < n ? sgb.query(j + 1, n - 1) : 0);
            int cur = cura + curb;
            int curcnt = k + 1 < sz(flippoints) ? (flippoints[k + 1] - j) : (n - j);
            if (cur > ans) {
                ans = cur;
                cnt = curcnt;
            } else if (cur == ans) {
                cnt += curcnt;
            }
            k++;
        }
    }

    cout << ans << ' ' << cnt << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}

