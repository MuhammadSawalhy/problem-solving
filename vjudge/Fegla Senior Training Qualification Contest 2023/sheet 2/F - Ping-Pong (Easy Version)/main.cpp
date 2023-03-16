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

vector<int> adj[100];
bool vis[100];

bool dfs(int a, int b) {
    if (a == b) return true;
    if (vis[a]) return false;
    vis[a] = true;
    bool ans = false;
    for (auto child: adj[a]) {
        ans |= dfs(child, b);
    }
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int t, a, b;
    vector<pair<int, int>> vec;
    int j = 0;
    while (n--) {
        cin >> t >> a >> b;
        a--, b--;

        if (t == 2) {
            memset(vis, 0, sizeof vis);
            cout << (dfs(a, b) ? "YES" : "NO") << endl;
            continue;
        }

        for (int i = 0; i < vec.size(); i++) {
            auto [c, d] = vec[i];
            if (c < a && a < d || c < b && b < d) {
                // j -> i
                adj[j].push_back(i);
            }
            if (a < c && c < b || a < d && d < b) {
                // i -> j
                adj[i].push_back(j);
            }
        }

        j++;
        vec.push_back({a, b});
    }

    return 0;
}
