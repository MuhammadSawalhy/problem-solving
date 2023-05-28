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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int x, y;
    cin >> x >> y;

    map<int, vector<int>> withx;
    map<int, vector<int>> withy;

    int lh[n][2];
    for (int i = 0; i < n; i++) {
        cin >> lh[i][0] >> lh[i][1];
        withx[lh[i][0]].push_back(lh[i][1]);
        withy[lh[i][1]].push_back(lh[i][0]);
    }

    for (auto &[x, v]: withx) {
        sort(all(v));
    }
    for (auto &[x, v]: withy) {
        sort(all(v));
    }

    int q;
    cin >> q;
    char I;
    while (q--) {
        cin >> I;
        if (I == 'R') {
            int i = lower_bound(all(withy[y]), x + 1) - withy[y].begin();
            if (i < withy[y].size()) {
                x = withy[y][i];
            }
        }
        if (I == 'L') {
            int i = upper_bound(all(withy[y]), x - 1) - withy[y].begin();
            if (i > 0) {
                x = withy[y][i - 1];
            }
        }
        if (I == 'U') {
            int i = lower_bound(all(withx[x]), y + 1) - withx[x].begin();
            if (i < withx[x].size()) {
                y = withx[x][i];
            }
        }
        if (I == 'D') {
            int i = upper_bound(all(withx[x]), y - 1) - withx[x].begin();
            if (i > 0) {
                y = withx[x][i - 1];
            }
        }

        cout << x << ' ' << y << endl;
    }


    return 0;
}
