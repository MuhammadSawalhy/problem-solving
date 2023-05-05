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

void solve() {
    int n;
    cin >> n;
    int xmin = 1e5, xmax = -1e5, ymin = 1e5, ymax = -1e5;
    while (n--) {
        char t;
        cin >> t;
        int x, y, r;
        if (t == 'p') {
            cin >> x >> y;
            xmin = min(x, xmin);
            xmax = max(x, xmax);
            ymin = min(y, ymin);
            ymax = max(y, ymax);
        } else if (t == 'c') {
            cin >> x >> y >> r;
            xmin = min(x - r, xmin);
            xmax = max(x + r, xmax);
            ymin = min(y - r, ymin);
            ymax = max(y + r, ymax);
        } else {
            cin >> x >> y;
            xmin = min(x, xmin);
            xmax = max(x, xmax);
            ymin = min(y, ymin);
            ymax = max(y, ymax);
            cin >> x >> y;
            xmin = min(x, xmin);
            xmax = max(x, xmax);
            ymin = min(y, ymin);
            ymax = max(y, ymax);
        }
    }

    cout << xmin << ' ' << ymin << ' ' << xmax << ' ' << ymax << '\n';
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
