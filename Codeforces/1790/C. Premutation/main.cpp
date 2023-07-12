// ﷽
#include <bits/stdc++.h>

using namespace std;

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

void solve() {
    int n;
    cin >> n;

    vector<int> maxpos(n + 1);
    vector<int> minpos(n + 1, 1e9);
    int perm[n - 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            cin >> perm[j];
            maxpos[perm[j]] = max(maxpos[perm[j]], j);
            minpos[perm[j]] = min(minpos[perm[j]], j);
        }
    }

    vector<pair<int, int>> res;

    for (int i = 1; i <= n; i++) {
        if (maxpos[i] == minpos[i]) {
            if (minpos[i] == 0)
                res.push_back({0, i});
            else
                res.push_back({n - 1, i});
        } else {
            res.push_back({maxpos[i], i});
        }
    }

    sort(all(res));
    for (int i = 0; i < n; i++) {
        cout << res[i].second << " ";
    }
    cout << endl;
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
