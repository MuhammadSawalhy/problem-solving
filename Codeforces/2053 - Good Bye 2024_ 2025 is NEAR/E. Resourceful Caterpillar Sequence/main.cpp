// ﷽
// https://codeforces.com/contest/2053/problem/E

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

void solve() {
    int n;
    cin >> n;
    vi adj[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Aron is the second to play
    // either 0 or 1 moves to win, otherwise tie

    int ans = 0;
    int leaves = 0;
    vi dist(n, 1e9), sum(n);

    queue<int> qu;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() == 1) {
            leaves++;
            dist[i] = 0;
            qu.push(i);
        }
    }

    ans += leaves * (n - leaves);

    while (qu.size()) {
        int top = qu.front();
        qu.pop();
        for (auto &i: adj[top]) {
            if (dist[i] == 1e9) {
                dist[i] = dist[top] + 1;
                qu.push(i);
            }
        }
    }

    debug(dist);
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cnt += dist[i] >= 2;
    }

    function<void(int, int)> calc = [&](int i, int p) {
        sum[i] += dist[i] >= 2;
        for (int j: adj[i]) {
            if (j == p) continue;
            calc(j, i);
            sum[i] += sum[j];
        }
        debug(i, sum[i]);
    };

    function<void(int, int)> dfs = [&](int i, int p) {
        if (dist[i] == 1) {
            if (p != -1 && dist[p] > 0) {
                ans += sum[i];
            }
            for (auto j: adj[i]) {
                if (j == p) continue;
                if (dist[j] > 0) {
                    ans += cnt - sum[j];
                }
            }
        }
        for (auto j: adj[i]) {
            if (j == p) continue;
            dfs(j, i);
        }
    };
    debug(cnt);

    calc(0, -1);
    dfs(0, -1);

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
