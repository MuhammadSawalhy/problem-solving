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

typedef complex<double> point;
point p[4];

void solve() {
    if (p[0] == p[2]) swap(p[0], p[1]);
    else if (p[1] == p[3]) swap(p[2], p[3]);
    else if (p[0] == p[3]) swap(p[0], p[1]), swap(p[2], p[3]);
    auto pp = p[1] + (p[0] - p[1]) + (p[3] - p[1]);
    cout << pp.real() << ' ' << pp.imag() << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << fixed << setprecision(3);
    double x, y;
    while (cin >> x) {
        cin >> y;
        p[0] = point(x, y);
        for (int i = 1; i < 4; i++)
            cin >> x >> y, p[i] = point(x, y);
        solve();
    }

    return 0;
}
