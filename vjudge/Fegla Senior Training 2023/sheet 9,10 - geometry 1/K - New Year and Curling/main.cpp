// ﷽
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, r;
    cin >> n >> r;

    int x[n];

    for (int i = 0; i < n; i++)
        cin >> x[i];

    double y[n];

    for (int i = 0; i < n; i++) {
        y[i] = r;
        for (int j = 0; j < i; j++) {
            double dx = x[i] - x[j];
            double dy = sqrtl((4ll * r * r) - (dx * dx));
            double newy = y[j] + dy;
            y[i] = max(y[i], newy);
        }
    }

    cout << fixed << setprecision(12);

    for (int i = 0; i < n; i++)
        cout << y[i] << ' ';

    return 0;
}
