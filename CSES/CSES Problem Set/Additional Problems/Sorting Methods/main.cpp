// ﷽
// https://cses.fi/problemset/task/1162

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;


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

const int N = 2e5 + 5;
int n, a[N];

int swap_two_adjancent() {
    int ans = 0;
    ordered_set<int> os;
    for (int i = 0; i < n; i++) {
        ans += i - os.order_of_key(a[i]);
        os.insert(a[i]);
    }

    return ans;
}

int swap_any_two() {
    int ans = 0;

    vector<int> b(a, a + n), pos(n + 1);

    for (int i = 0; i < n; i++) {
        b[i]--;
        pos[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int x = b[i];
        if (pos[x] == x) continue;
        while (pos[x] != x) {
            swap(b[pos[x]], b[x]);
            int y = pos[x];
            pos[x] = x;
            x = y;
            ans++;
        }
        ans--;
    }

    return ans;
}

// source: https://codeforces.com/blog/entry/18051
template<typename T = long long, T DEFAULT = 0>
struct Segtree {
    int n = 0;
    vector<T> tree;

    Segtree() = default;
    Segtree(int n) : n(n) { tree.assign(n * 2, DEFAULT); }

    inline T merge(const T &a, const T &b) { return max(a, b); }

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

int move_item_to_pos() {
    int ans = 0;
    Segtree sg(n + 1);

    for (int i = 0; i < n; i++) {
        int cur = max(1ll, sg.query(1, a[i]) + 1);
        debug(a[i], cur);
        sg.update(a[i], cur);
        maxit(ans, cur);
    }

    return n - ans;
}

int move_to_front() {
    vector<int> b(a, a + n), pos(n + 1);

    for (int i = 0; i < n; i++) {
        b[i]--;
        pos[b[i]] = i;
    }

    int i = n - 2;
    while (i >= 0 && pos[i] < pos[i + 1]) i--;

    return i + 1;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << swap_two_adjancent() << ' ';
    cout << swap_any_two() << ' ';
    cout << move_item_to_pos() << ' ';
    cout << move_to_front() << ' ';
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
