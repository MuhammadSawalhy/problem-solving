// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> adj[n];
    vector<int> dp(n, -1);

    for (int i = 0, a, b; i < n - 1; i++) {
        cin >> a >> b, a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    function<int(int, int)> solve = [&](int i, int p) -> int {
        int &res = dp[i];
        if (~res) return res;

        int children_taken = 0, not_taken = 1;
        for (auto j : adj[i]) {
            if (p == j) continue;
            not_taken += solve(j, i);
            children_taken++;
            for (auto k : adj[j]) {
                if (k == i) continue;
                children_taken += solve(k, j);
            }
        }
    
        return res = min(children_taken, not_taken);
    };

    solve(0, 0);

    cout << dp[0] << endl;

    return 0;
}
