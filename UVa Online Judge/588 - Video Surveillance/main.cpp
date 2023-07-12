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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, t = 0;
    while (cin >> n, n) {
        int sx = -1e9, ex = 1e9, sy = -1e9, ey = 1e9;
    
        vector<pair<int, int>> vert(n);
        for(int i = 0; i < n; i++)
            cin >> vert[i].first >> vert[i].second;

        vert.push_back(vert[0]);
        vert.push_back(vert[1]);
        vert.push_back(vert[2]);
        for (int i = 0; i + 3 < (int)vert.size(); i++) {
            auto [a, b] = vert[i];
            auto [x, y] = vert[i + 1];
            auto [j, k] = vert[i + 2];
            auto [w, e] = vert[i + 3];

            // if cavity -> restrict our visibility region
        
            if (e == k) {
                assert(b == y && x == j);
                if ((a < x) == (w < x)) {
                    ey = min(ey, max(b, e));
                    sy = max(sy, min(b, e));
                }
            } else {
                assert(a == x && j == w);
                if ((b < y) == (e < y)) {
                    ex = min(ex, max(a, w));
                    sx = max(sx, min(a, w));
                }
            }
        }

        bool ok = sx <= ex && sy <= ey;
        cout << "Floor #" << ++t << endl;
        if (ok)
            cout << "Surveillance is possible." << endl;
        else
            cout << "Surveillance is impossible." << endl;
        cout << endl;
    }

    return 0;
}
