// ﷽
#include <bits/stdc++.h>

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n*n);
    iota(all(v), 1);
    do {
        set<int> s;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) {
                    s.insert(abs(v[i * n + j] - v[(i - 1) * n + j]));
                }
                if (i < n - 1) {
                    s.insert(abs(v[i * n + j] - v[(i + 1) * n + j]));
                }
                if (j < 0) {
                    s.insert(abs(v[i * n + j] - v[i * n + j - 1]));
                }
                if (j < n - 1) {
                    s.insert(abs(v[i * n + j] - v[i * n + j + 1]));
                }
            }
        }
        if (s.size() == n * n - 1) {
            vector<vector<int>> vec(n);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    vec[i].push_back(v[i * n + j]);
            }
            debug(vec);
        }
    } while (next_permutation(all(v)));
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
