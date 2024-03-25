// ﷽
// https://codeforces.com/contest/1946/problem/C

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
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

const int N = 1e5 + 5;
vector<int> adj[N];

pair<int, int> dfs(int i, int p, int x) {
    int k = 0;
    int rem = 1;
    for (auto j: adj[i]) {
        if (j != p) {
            auto y = dfs(j, i, x);
            k += y.first;
            rem += y.second;
        }
    }

    if (i != 0 && rem >= x) {
        k++;
        rem = 0;
    } else if (i == 0) {
        if (rem < x) k--;
    }

    return {k, rem};
}

void solve() {
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int l = 0, r = n + 1;

    debug(n, k);
    while (r - l > 1) {
        int mid = (l + r) / 2;
        debug(mid);
        if (dfs(0, 0, mid).first >= k) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;

    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
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
