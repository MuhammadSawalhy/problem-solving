// ﷽
// https://codeforces.com/contest/1975/problem/E

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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n), black(n), parent(n, -1), cnt(n);
    multiset<int> allcnt;
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    function<void(int)> dfs = [&](int i) {
        for (auto j: adj[i]) {
            if (j == parent[i]) continue;
            parent[j] = i;
            dfs(j);
        }
    };

    set<int> two;
    auto toggle = [&](int u) {
        black[u] ^= 1;
        if (black[u]) allcnt.insert(cnt[u]);
        else allcnt.erase(allcnt.find(cnt[u]));

        if (parent[u] == -1) return;
        if (black[parent[u]]) allcnt.erase(allcnt.find(cnt[parent[u]]));
        if (cnt[parent[u]] == 2) two.erase(parent[u]);
        cnt[parent[u]] += black[u] ? 1 : -1;
        if (black[parent[u]]) allcnt.insert(cnt[parent[u]]);
        if (cnt[parent[u]] == 2) two.insert(parent[u]);
    };

    auto check = [&]() -> bool {
        if (allcnt.size() == 0) return false;
        if (allcnt.size() == 1) return true;

        // first case
        int left1 = *allcnt.begin();
        int left2 = *next(allcnt.begin());
        int right1 = *prev(allcnt.end());

        if (left1 == 0 && left2 == 1 && right1 == 1)
            return true;

        // second case
        if (allcnt.size() >= 3) {
            int left3 = *next(next(allcnt.begin()));
            int right2 = *prev(prev(allcnt.end()));

            return left1 == 0 && left2 == 0 && (left3 == 1 || left3 == 2) &&
                   right1 == 2 && (right2 == 1 || right2 == 0) &&
                   (parent[*two.begin()] == -1 || !black[parent[*two.begin()]]);
        }

        return false;
    };

    dfs(0);

    for (int i = 0; i < n; i++) {
        if (a[i]) toggle(i);
    }

    while (q--) {
        int u;
        cin >> u, --u;

        toggle(u);
        cout << (check() ? "YES" : "NO") << '\n';
    }
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
