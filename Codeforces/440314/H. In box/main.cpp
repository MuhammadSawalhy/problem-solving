// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

const int LIMIT = 2e5;

multiset<int> values;
vector<bool> asdf;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n];
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v, u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];

    values.clear();
    vector<int> vals;
    vector<bool> vis(n);
    queue<int> qu;
    qu.push(0);

    while (qu.size()) {
        int i = qu.front();
        qu.pop();
        if (vis[i]) continue;
        vals.push_back(x[i]);
        values.insert(x[i]);
        vis[i] = true;
        for (auto j: adj[i])
            qu.push(j);
    }

    vector<vector<bool>> dp(vals.size() + 1, vector<bool>(LIMIT));
    dp[0][0] = 1;

    for (int i = 0; i < vals.size(); i++) {
        for (int j = 0; j < LIMIT; j++) {
            if (!dp[i][j]) continue;
            dp[i + 1][j] = 1;
            if (j + vals[i] < LIMIT)
                dp[i + 1][j + vals[i]] = 1;
        }
    }

    assert(vals.size() == values.size());
    asdf = dp[vals.size()];
}

void print(int player) {
    if (player == 1) cout << "MaghrabyJr\n";
    else cout << "Mohamed\n";
    exit(0);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();
    auto maghraby = values;
    auto ma = asdf;
    solve();
    auto mohamed = values;
    auto mo = asdf;


    {
        debug(maghraby);
        debug(mohamed);

        multiset<int> ma = maghraby;
        for (auto x: ma) {
            if (mohamed.count(x) && maghraby.count(x)) {
                mohamed.erase(mohamed.find(x));
                maghraby.erase(maghraby.find(x));
            }
        }

        debug(maghraby);
        debug(mohamed);

        int mgh = 0;
        int moh = 0;

        for (auto x: maghraby) {
            mgh += x;
        }

        for (auto x: mohamed) {
            moh += x;
        }

        if (mgh > moh) {
            print(1);
        }
    }

    {
        for (int i = 0; i < LIMIT; i++) {
            if (ma[i] && !mo[i]) {
                print(1);
            }
        }
    }

    print(2);

    return 0;
}
