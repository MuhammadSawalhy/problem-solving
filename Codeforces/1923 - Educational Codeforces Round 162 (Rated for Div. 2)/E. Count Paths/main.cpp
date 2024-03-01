// ﷽
// https://codeforces.com/contest/1923/problem/E

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
vector<int> cnt(N);
int c[N];
int ans = 0;

// store previous value
// before going to children set it to 1
// return to parent and restore previous value value + 1(node i)
void dfs(int i, int p) {
    ans += cnt[c[i]];
    int prev = cnt[c[i]];

    for (auto j: adj[i]) {
        if (j == p) continue;
        cnt[c[i]] = 1;
        dfs(j, i);
    }

    cnt[c[i]] = prev + 1;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
        cnt[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    dfs(0, -1);
    cout << ans << endl;

    // clear adj
    for (int i = 0; i < n; i++) adj[i].clear();
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
