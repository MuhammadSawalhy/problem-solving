// ﷽
// https://codeforces.com/problemset/problem/708/C

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

const int N = 4e5 + 5;
vector<int> adj[N];
bool ans[N];
int sz[N], mx[N];
int n;

void calc(int i, int p) {
    sz[i] = 1;
    for (auto j: adj[i]) {
        if (j == p) continue;
        calc(j, i);
        maxit(mx[i], mx[j]);
        sz[i] += sz[j];
    }

    if (sz[i] <= n / 2)
        maxit(mx[i], sz[i]);
}

void dfs(int i, int p, int up) {
    set<pair<int, int>> s{{up, p}};

    int cnt = 0, k = -1;
    for (auto j: adj[i]) {
        if (j == p) continue;
        s.insert({mx[j], j});
        if (sz[j] > n / 2) cnt++, k = j;
    }

    for (auto j: adj[i]) {
        if (j == p) continue;
        s.erase({mx[j], j});
        int cur = prev(s.end())->first;
        if (n - sz[j] <= n / 2)
            maxit(cur, n - sz[j]);
        s.insert({mx[j], j});
        dfs(j, i, cur);
    }

    if (cnt > 1) return;
    if (cnt == 0) {
        // check up
        if (n - sz[i] > n / 2)
            ans[i] = up >= n - sz[i] - n / 2;
        else
            ans[i] = 1;
        return;
    }

    // check k
    ans[i] = n - sz[i] <= n / 2 && mx[k] >= sz[k] - n / 2;
}

void solve() {
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calc(0, 0);

    dfs(0, 0, 0);

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
