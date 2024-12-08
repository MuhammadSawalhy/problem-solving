// ﷽
// https://codeforces.com/contest/2050/problem/G

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

const int N = 2e5 + 9;
int deg[N];

struct Centroids {
    vector<vector<int>> adj;
    vector<bool> removed;
    vector<int> par, sz;
    int n;

    Centroids(int n) : n(n) {
        adj.resize(n), removed.resize(n);
        sz.resize(n), par.assign(n, -1);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void find_size(int i, int p = -1) {
        sz[i] = 1;
        for (int j: adj[i]) {
            if (j == p || removed[j]) continue;
            find_size(j, i), sz[i] += sz[j];
        }
    }

    int find_centroid(int i, int p, int n) {
        for (int j: adj[i]) {
            if (j == p || removed[j]) continue;
            if (sz[j] > n / 2) return find_centroid(j, i, n);
        }
        return i;
    }

    int find_y(int i, int p) {
        int y = deg[i] - 1;
        for (int j: adj[i]) {
            if (j == p || removed[j]) continue;
            maxit(y, find_y(j, i) + deg[i] - 2);
        }
        return y;
    }

    int find_ans(int i, int p, int cnt) {
        debug(i, p, cnt);
        int ans = cnt + deg[i] - 1;
        for (int j: adj[i]) {
            if (j == p || removed[j]) continue;
            maxit(ans, find_ans(j, i, cnt + deg[i] - 2));
        }
        return ans;
    }

    int build(int i = 0, int p = -1) {
        find_size(i);
        int ans = 0, cnt = 0;
        int c = find_centroid(i, -1, sz[i]);
        debug(c);

        for (int j: adj[c])
            if (!removed[j]) {
                auto y = find_y(j, c);
                auto x = find_ans(j, c, max(cnt + deg[c] - 2, deg[c] - 1));
                maxit(cnt, y);
                maxit(ans, y + deg[c] - 1);
                maxit(ans, x);
            }

        debug(ans);

        removed[c] = true, par[c] = p;
        for (int j: adj[c])
            if (!removed[j]) maxit(ans, build(j, c));
        return ans;
    }
};

void solve() {
    int n;
    cin >> n;
    Centroids cen(n);

    int ans = 0;

    for (int i = 0; i < n; i++) deg[i] = 0;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        cen.add_edge(u, v);
        deg[u]++, deg[v]++;
        maxit(ans, deg[u]);
        maxit(ans, deg[v]);
    }

    maxit(ans, cen.build());

    cout << ans << endl;
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
