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

void solve() {
    int m;
    int a;
    int n;
    cin >> m;

    vector<int> lot[m];
    for (int i = 0; i < m; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a;
            lot[i].push_back(a);
        }
    }


    int ans[m];

    set<int> s;
    for (int i = m - 1; i >= 0; i--) {
        bool ok = false;
        for (int j = 0; j < lot[i].size(); j++) {
            if (s.count(lot[i][j])) continue;
            ok = true;
            ans[i] = lot[i][j];
            s.insert(lot[i][j]);
        }
        if (!ok) return cout << "-1\n", void();
    }

    for (auto i: ans)
        cout << i << ' ';
    cout << '\n';
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
