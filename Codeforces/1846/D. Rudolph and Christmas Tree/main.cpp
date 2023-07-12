// ﷽
#include <bits/stdc++.h>
#include <iomanip>

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
    int n, b, h;
    cin >> n >> b >> h;

    double ans = n * (0.5 * b * h);

    int y[n];
    for (int i = 0; i < n; i++) {
        cin >> y[i];
        if (i > 0 && y[i] - y[i - 1] < h) {
            int dy = y[i] - y[i - 1];
            int H = h - (dy);
            double B = b - (dy * (1.0 * b / h));
            ans -= 0.5 * H * B;
        }
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cout << fixed << setprecision(15);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
