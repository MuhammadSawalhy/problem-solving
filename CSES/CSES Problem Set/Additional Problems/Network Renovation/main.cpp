// ﷽
// https://cses.fi/problemset/task/1704

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

const int N = 2e5 + 5;
vi adj[N];
int cnt[N];
vii ans;

void calc(int i, int p) {
    bool leaf = true;
    for (auto j: adj[i]) {
        if (j == p) continue;
        calc(j, i);
        cnt[i] += cnt[j];
        leaf = false;
    }

    cnt[i] += leaf;
}

int centriod = -1;

void dfs(int i, int p, int up) {
    bool ok = up <= cnt[0] / 2;
    for (auto j: adj[i]) {
        if (j == p) continue;
        dfs(j, i, up + cnt[i] - cnt[j]);
        ok &= cnt[j] <= cnt[0] / 2;
    }

    if (ok) centriod = i;
}

vvi leafs;

void getleafs(int i, int p, vi &v) {
    bool leaf = true;
    for (auto j: adj[i]) {
        if (j == p) continue;
        getleafs(j, i, v);
        leaf = false;
    }
    if (leaf) v.push_back(i);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    calc(0, 0);
    dfs(0, 0, 0);
    assert(~centriod);

    for (auto j: adj[centriod]) {
        leafs.push_back({});
        getleafs(j, centriod, leafs.back());
    }

    debug(centriod);
    debug(leafs);

    set<pii> s;

    for (int i = 0; i < sz(leafs); i++) {
        s.insert({leafs[i].size(), i});
    }

    while (s.size() > 1) {
        auto [x, i] = *prev(s.end());
        s.erase(prev(s.end()));
        auto [y, j] = *prev(s.end());
        s.erase(prev(s.end()));

        ans.push_back({leafs[i].back(), leafs[j].back()});
        leafs[i].pop_back(), leafs[j].pop_back();
        if (x > 1)
            s.insert({x - 1, i});
        if (y > 1)
            s.insert({y - 1, j});
    }

    if (s.size()) {
        assert(s.begin()->first == 1);
        ans.push_back({leafs[s.begin()->second].back(), centriod});
    }

    cout << sz(ans) << '\n';
    for (auto [i, j]: ans) {
        cout << j + 1 << ' ' << i + 1 << endl;
    }
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
