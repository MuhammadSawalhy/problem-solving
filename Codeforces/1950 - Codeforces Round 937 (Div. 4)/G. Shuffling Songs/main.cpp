// ﷽
// https://codeforces.com/contest/1950/problem/G

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
    vector<int> g(n), w(n);
    vector<string> gs, ws;
    string x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        gs.push_back(x);
        ws.push_back(y);
    }

    for (int i = 0; i < n; i++) {
        g[i] = find(all(gs), gs[i]) - gs.begin();
        w[i] = find(all(ws), ws[i]) - ws.begin();
    }


    vector<vector<int>> adj(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (g[i] == g[j] || w[i] == w[j]) {
                adj[i][j] = 1;
                adj[j][i] = 1;
            }
        }
    }

    vector<vector<bool>> dp(n, vector<bool>(1 << n, false));

    for (int i = 0; i < n; ++i) {
        dp[i][1 << i] = true;
    }

    for (int mask = 0; mask < 1 << n; mask++) {
        for (int i = 0; i < n; i++) {
            if (!dp[i][mask]) continue;
            for (int j = 0; j < n; j++) {
                if (mask & (1 << j)) continue;
                if (!adj[i][j]) continue;
                dp[j][mask | (1 << j)] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < 1 << n; mask++) {
            if (dp[i][mask])
                maxit(ans, (int) __popcount(mask));
        }
    }

    cout << n - ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
