// ﷽
// https://codeforces.com/contest/2049/problem/C

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

const int N = 3e5;
int vis[N];
set<int> adj[N];

int n, x, y;

vector<int> nodes;
bool found = false;

void dfs1(int i) {
    nodes.push_back(i);
    vis[i] = 1;
    for (auto j: adj[i]) {
        if (vis[j] == 0) {
            dfs1(j);
            return;
        }
    }
}

void dfs2(int i) {
    nodes.push_back(i);
    vis[i] = 2;
    for (auto j: adj[i]) {
        if (vis[j] == 0) {
            dfs2(j);
            return;
        }
    }
}

void solve() {
    cin >> n >> x >> y;
    x--, y--;

    for (int i = 0; i < n; i++) {
        adj[i].insert((i - 1 + n) % n);
        adj[i].insert((i + 1 + n) % n);
    }

    adj[x].insert(y);
    adj[y].insert(x);

    vi ans(n);
    nodes.clear();
    nodes.push_back(x);
    vis[x] = 1;
    dfs1(y);
    debug(nodes);

    assert(nodes.size() > 2);
    if (nodes.size() % 2 == 0) {
        for (int i = 0; i < nodes.size(); i++) {
            ans[nodes[i]] = i & 1;
        }
    } else {
        for (int i = 0; i < nodes.size() - 1; i++) {
            ans[nodes[i]] = i & 1;
        }
        ans[nodes.back()] = 2;
    }

    nodes.clear();
    nodes.push_back(x);
    vis[x] = 2;
    dfs2(y);
    debug(nodes);

    if (nodes.size() > 2) {
        if (nodes.size() % 2 == 0) {
            for (int i = 0; i < nodes.size(); i++) {
                ans[nodes[i]] = i & 1;
            }
        } else {
            for (int i = 0; i < nodes.size() - 1; i++) {
                ans[nodes[i]] = i & 1;
            }
            ans[nodes.back()] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < n; i++) vis[i] = 0, adj[i].clear();
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
