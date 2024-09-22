// ﷽
// https://usaco.org/index.php?page=viewproblem2&cpid=965

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
#define pii pair<int, int>
#define vvi vector<vector<int>>
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    #ifndef SAWALHY
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);
    #endif

    int n;
    cin >> n;

    string s;

    vector<string> cows{
            "Beatrice",
            "Belinda",
            "Bella",
            "Bessie",
            "Betsy",
            "Blue",
            "Buttercup",
            "Sue",
    };

    vector<int> adj[8];
    vector<int> deg(8), vis(8);

    while (n--) {
        string u, v;
        cin >> u;
        for (int i = 0; i < 5; i++) cin >> v;
        int uu = find(all(cows), u) - cows.begin();
        if (uu == cows.size()) cows.push_back(u);
        int vv = find(all(cows), v) - cows.begin();
        if (vv == cows.size()) cows.push_back(v);
        debug(uu, vv);
        adj[uu].push_back(vv);
        adj[vv].push_back(uu);
        deg[uu]++;
        deg[vv]++;
    }

    debug(deg);

    vector<int> ans;

    function<void(int)> dfs = [&](int i) {
        if (vis[i]) return;
        vis[i] = true;
        ans.push_back(i);
        for(auto j : adj[i]) {
            dfs(j);
        }
    };

    for (int i = 0; i < 8; i++) {
        if (deg[i] <= 1)
            dfs(i);
    }

    debug(ans);

    assert(sz(ans) == 8);
    for (auto x : ans) cout << cows[x] << endl;

    return 0;
}
