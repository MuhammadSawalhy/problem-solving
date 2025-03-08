#include <bits/stdc++.h>
using namespace std;

struct Mouse {
    int x, y, s;
};
vector<Mouse> mice;
vector<double> origin_dist;
vector<vector<double>> mouse_dist;
int n;
double m;

double dist(int x1, int y1, int x2, int y2) {
    return hypot(x1 - x2, y1 - y2);
}

bool check(double v0) {
    const double INF = 1e18;
    vector<vector<double>> dp(1 << n, vector<double>(n + 1, INF));
    dp[0][n] = 0;

    for (int j = 0; j < n; ++j) {
        double t = origin_dist[j] / v0;
        if (t + 0 > mice[j].s) continue;
        dp[1 << j][j] = t;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int last = 0; last < n; ++last) {
            if (dp[mask][last] >= INF) continue;
            int cnt = __builtin_popcount(mask);
            double vel = v0 * pow(m, cnt);
            for (int j = 0; j < n; ++j) {
                if (mask & (1 << j)) continue;
                double t = mouse_dist[last][j] / vel;
                double arrival = dp[mask][last] + t;
                if (arrival > mice[j].s) continue;
                int new_mask = mask | (1 << j);
                dp[new_mask][j] = min(dp[new_mask][j], arrival);
            }
        }
    }

    int full = (1 << n) - 1;
    for (int j = 0; j < n; ++j)
        if (dp[full][j] < INF) return true;
    return false;
}

int main() {
    cin >> n;
    mice.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> mice[i].x >> mice[i].y >> mice[i].s;
    }
    cin >> m;

    origin_dist.resize(n);
    for (int i = 0; i < n; ++i)
        origin_dist[i] = dist(0, 0, mice[i].x, mice[i].y);

    mouse_dist.resize(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mouse_dist[i][j] = dist(mice[i].x, mice[i].y, mice[j].x, mice[j].y);

    double low = 0, high = 1e9, ans = high;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (low + high) / 2;
        if (check(mid)) {
            ans = mid;
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}
