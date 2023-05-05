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

    int n;
    while (cin >> n, n) {
        int x[n], y[n];
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        int first = 0, second = 0;
        for (int i = 0; i < n; i++) {
            if (x[i] == x[n / 2] || y[i] == y[n / 2]) continue;

            if ((x[i] - x[n / 2]) * (y[i] - y[n / 2]) > 0) {
                first++;
            } else {
                second++;
            }
        }

        cout << first << ' ' << second << '\n';
    }

    return 0;
}
