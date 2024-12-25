#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int m, b, hh, n;
    cin >> m >> b >> hh >> n;

    int a[m];
    for (int i = 0; i < m; i++) cin >> a[i];

    int h[n + 1];
    h[0] = hh;
    for (int i = 1; i <= n; i++) cin >> h[i];

    int c[m][n + 1];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j < m; j++) cin >> c[j][i];

    long long minval = 1e18, chosen = -1;

    for (int i = 1; i <= n; i++) {
        long long cost = h[0] + h[i];
        int bb = b;

        vector<pair<int, int>> mines;
        for (int j = 0; j < m; j++) {
            cost += c[j][i] * a[j];
            mines.push_back({c[j][0] - c[j][i], a[j]});
        }

        sort(mines.begin(), mines.end());
        for (int i = 0; i < m; i++) {
            int tomove = min(bb, mines[i].second);
            bb -= tomove;
            cost += tomove * mines[i].first;
        }

        if (cost < minval) {
            minval = cost;
            chosen = i;
        }
    }

    assert(minval < 1e18);
    cout << chosen << endl;
    cout << minval << endl;

    return 0;
}
