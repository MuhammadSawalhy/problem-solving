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

#define ll long long
#define int long long
#define all(v) v.begin(), v.end()

void solve() {
    int n, m, h;
    cin >> n >> m >> h;

    int t[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t[i][j];
        }
    }

    vector<array<int, 3>> optimal;

    for (int i = 0; i < n; i++) {
        sort(t[i], t[i] + m);
        int pts = 0, pen = 0;

        for (int j = 0, total = 0; j < m; j++) {
            if (total + t[i][j] > h) break;
            total += t[i][j];
            pen += total;
            pts++;
        }

        optimal.push_back({-pts, pen, i});
    }

    sort(all(optimal));
    for (int i = 0; i < n; i++) {
        if (optimal[i][2] == 0) {
            cout << i + 1 << '\n';
            return;
        }
    }
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
