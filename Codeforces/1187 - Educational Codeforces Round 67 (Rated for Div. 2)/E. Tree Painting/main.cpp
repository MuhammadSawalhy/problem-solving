// ﷽
// https://codeforces.com/contest/1187/problem/E

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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x) v = min(v, x)
#define maxit(v, x) v = max(v, x)

const int N = 2e5 + 5;
vector<int> adj[N];
int n;
int ans = 0;

int sz[N], value[N];

void calc_size(int u, int p) {
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == p) continue;
        calc_size(v, u);
        sz[u] += sz[v];
        value[u] += value[v];
    }
    value[u] += sz[u];
}

void calc_ans(int u, int p, int up) {
    int cur = up + value[u] + n - sz[u];
    maxit(ans, cur);
    for (auto v: adj[u]) {
        if (v == p) continue;
        calc_ans(v, u, value[u] - sz[u] - value[v] + up + n - sz[v]);
    }
}

void solve() {
    cin >> n;

    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calc_size(0, 0);
    calc_ans(0, 0, 0);

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}
