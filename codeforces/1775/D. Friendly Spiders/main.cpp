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

const int N = 4e5;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> fact(N);

    for (int i = 2; i < N; i++) {
        if (fact[i].size()) continue;
        for (int j = i; j < N; j += i) {
            fact[j].push_back(i);
        }
    }

    vector<bool> vis(N);
    vector<vector<int>> ind(N);

    for (int i = 0; i < n; i++) {
        for (auto f: fact[a[i]]) {
            ind[f].push_back(i);
        }
    }

    int s, t;
    cin >> s >> t, s--, t--;

    int i = 0;
    vector<int> dist(n, 1e9);
    vector<array<int, 2>> qu{{s, -1}};
    bool found = false;
    dist[s] = 0;
    while (i < qu.size()) {
        auto [j, p] = qu[i];
        if (j == t) {
            found = true;
            break;
        }
        for (auto f: fact[a[j]]) {
            if (vis[f]) continue;
            vis[f] = true;
            for (auto k: ind[f]) {
                if (dist[j] + 1 < dist[k]) {
                    dist[k] = dist[j] + 1;
                    qu.push_back({k, i});
                }
            }
        }

        i++;
    }

    if (!found) {
        cout << "-1\n";
    } else {
        vector<int> path;

        while (i != -1) {
            path.push_back(qu[i][0]);
            i = qu[i][1];
        }
        reverse(all(path));

        cout << path.size() << endl;
        for (auto p: path) cout << p + 1 << " ";
    }

    return 0;
}
