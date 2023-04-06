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

    int n, m;
    cin >> n >> m;

    vector<int> dist(n + 1), indeg(n + 1);
    vector<int> adj[n + 1];

    for (int i = 1, x, y; i <= m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    set<pair<int, int>> s;
    for (int i = 1; i <= n; i++) {
        s.insert({indeg[i], i});
    }

    while (s.size()) {
        auto [d, i] = *s.begin();
        s.erase(s.begin());
        assert(d == 0);
        for (auto j: adj[i]) {
            dist[j] = max(dist[j], dist[i] + 1);
            if (s.count({indeg[j], j})) {
                s.erase({indeg[j], j});
                indeg[j]--;
                s.insert({indeg[j], j});
            }
        }
    }

    cout << *max_element(all(dist)) << endl;

    return 0;
}
