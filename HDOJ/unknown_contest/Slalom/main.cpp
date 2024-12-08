#include <bits/stdc++.h>
using namespace std;

using ld = long double;

const int N = 1001;
vector<pair<ld, array<ld, 2>>> gates(N);
vector<array<ld, 2>> shortest(N);
const ld inf = 1e18;
int n;

void solve() {
    ld sx, sy;
    cin >> sx >> sy;

    string line;
    for (int i = 0; i < n; i++) {
        cin >> gates[i].first;
        cin >> gates[i].second[0] >> gates[i].second[1];
    }

    for (int i = 0; i < n; i++) {
        auto [y, points] = gates[i];
        for (int p = 0; p < 2; p++) {
            shortest[i][p] = inf;
            ld x = points[p];
            ld mn_ang = -inf, mx_ang = inf;
            for (int j = i - 1; j >= 0; j--) {
                auto [y1, points1] = gates[j];
                ld left = atan2l((y1 - y), (points1[0] - x));
                ld right = atan2l((y1 - y), (points1[1] - x));
                assert(right <= left);
                mn_ang = max(mn_ang, right);
                mx_ang = min(mx_ang, left);
                if (mn_ang <= left && left <= mx_ang) {
                    ld dx = points1[0] - x,  dy = y1 - y;
                    shortest[i][p] = min(shortest[i][p], shortest[j][0] + sqrtl(dx * dx + dy * dy));
                }
                if (mn_ang <= right && right <= mx_ang) {
                    ld dx = points1[1] - x,  dy = y1 - y;
                    shortest[i][p] = min(shortest[i][p], shortest[j][1] + sqrtl(dx * dx + dy * dy));
                }
            }
            ld ang = atan2l((sy - y), (sx - x));
            if (mn_ang <= ang && ang <= mx_ang) {
                shortest[i][p] = min(shortest[i][p], sqrtl((sx - x) * (sx - x) + (sy - y) * (sy - y)));
            }
        }
    }

    ld ans = inf;
    ld mn = -inf, mx = inf;
    for (int i = n - 1; i >= 0; i--) {
        auto [x1, x2] = gates[i].second;
        mn = max(mn, x1);
        mx = min(mx, x2);
        if (mn <= x1 && x1 <= mx) {
            ld dy = gates[i].first - gates[n - 1].first;
            ans = min(ans, shortest[i][0] + dy);
        }
        if (mn <= x2 && x2 <= mx) {
            ld dy = gates[i].first - gates[n - 1].first;
            ans = min(ans, shortest[i][1] + dy);
        }
    }

    if (mn <= sx && sx <= mx) {
        ans = min(ans, sy - gates[n - 1].first);
    }

    cout << ans << endl;
}

int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(11);

    while (cin >> n, n) {
        solve();
    }

    return 0;
}
