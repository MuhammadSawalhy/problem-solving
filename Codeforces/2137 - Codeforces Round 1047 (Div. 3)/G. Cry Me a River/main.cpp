// ﷽
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> adj[n];
    vector<int> radj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    vector<vector<bool>> is_lose(2, vector<bool>(n));
    vector<int> child_lose(n);

    std::function<void(int)> update_lose_0;
    std::function<void(int)> update_lose_1;


    update_lose_0 = [&](int i) {
        if (is_lose[0][i]) return;
        is_lose[0][i] = true;
        for (auto j: radj[i]) {
            update_lose_1(j);
        }
    };

    update_lose_1 = [&](int i) {
        if (is_lose[1][i]) return;
        is_lose[1][i] = true;
        for (auto j: radj[i]) {
            child_lose[j]++;
            if (child_lose[j] == adj[j].size()) {
                update_lose_0(j);
            }
        }
    };

    while (q--) {
        int x, u;
        cin >> x >> u;
        u--;
        if (x == 1) {
            update_lose_0(u);
            update_lose_1(u);
        } else {
            cout << (is_lose[0][u] ? "NO\n" : "YES\n");
        }
    }
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
