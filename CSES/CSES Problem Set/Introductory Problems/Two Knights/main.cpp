// Date: 01-01-2023
#include <bits/stdc++.h>

#define debug(...)
#ifdef SAWALHY
#include "debug.hpp"
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    for (int k = 1; k <= n; k++) {
        // a knight has 8 points spots, consider only the top 4
        // because considering the bottom will result in duplication
        // and we don't care about the order of knight (identical knights)
        //
        // for each cell we can consider it as attack point, but we can't consider all
        // cells as attack points because the knight will be outside the board for some cells
        // we can choose (k - 1) * (k - 2) points as attack points for each type of the top
        // attack points of a knight

        ll cells = k * k;
        ll all = cells * (cells - 1) / 2;
        ll attacks = 4 * (k - 1) * (k - 2);
        ll ans = all - attacks;
        cout << ans << endl;
    }

    return 0;
}
