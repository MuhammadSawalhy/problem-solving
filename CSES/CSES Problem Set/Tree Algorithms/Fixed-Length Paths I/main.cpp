// ﷽
// https://cses.fi/problemset/task/2080

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

int n, k;

struct Centroids {
    vector<vector<int>> edges;
    vector<bool> removed;
    vector<int> par, sz, fr;
    int n;

    Centroids(int n) : n(n) {
        edges.resize(n), removed.resize(n), fr.resize(n);
        sz.resize(n), par.assign(n, -1);
    }

    void add_edge(int a, int b) {
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    void find_size(int i, int p = -1) {
        sz[i] = 1;
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            find_size(j, i), sz[i] += sz[j];
        }
    }

    int find_centroid(int i, int p, int n) {
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            if (sz[j] > n / 2) return find_centroid(j, i, n);
        }
        return i;
    }

    int calc(int i, int p, int d) {
        if (d > k) return 0;
        int ans = fr[k - d];
        debug(i, p, d, fr[k-d]);
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            ans += calc(j, i, d + 1);
            if (p == -1) add(j, i, d + 1);
        }
        return ans;
    }

    void add(int i, int p, int d) {
        if (d > k) return;
        fr[d]++;
        for (int j: edges[i]) {
            if (j == p || removed[j]) continue;
            add(j, i, d + 1);
        }
    }

    int build(int v = 0, int p = -1) {
        find_size(v);
        int c = find_centroid(v, -1, sz[v]);
        fr[0] = 1;
        int ans = calc(c, -1, 0);
        for (int i = 0; i < sz[v]; i++) fr[i] = 0;
        removed[c] = true, par[c] = p;

        for (int x: edges[c])
            if (!removed[x]) ans += build(x, c);
        return ans;
    }
};

void solve() {
    cin >> n >> k;

    Centroids G(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G.add_edge(a, b);
    }

    int ans = G.build();
    cout << ans << '\n';
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
