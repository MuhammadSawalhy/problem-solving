#include <bits/stdc++.h>
using namespace std;

using arr = array<long long, 3>;
vector<arr> points;

arr sub(const arr &a, const arr &b) {
    return {a[0] - b[0], a[1] - b[1], 0};
}

long long cross(const arr &a, const arr b) {
    return a[0] * b[1] - a[1] * b[0];
}

long long dot(const arr &a, const arr b) {
    return a[0] * b[0] + a[1] * b[1];
}

bool point_in_triangle(arr point, arr a, arr b, arr c) {
    long long d1, d2, d3;
    bool has_neg, has_pos;

    d1 = cross(sub(point, a), sub(b, a));
    d2 = cross(sub(point, b), sub(c, b));
    d3 = cross(sub(point, c), sub(a, c));

    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    if (d1 == 0 || d2 == 0 || d3 == 0) return false;

    return !(has_neg && has_pos);
}


int32_t main(int32_t argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);

    int P, T;
    cin >> P >> T;

    for (int i = 0, x, y; i < P; i++) {
        cin >> x >> y;
        points.push_back({x, y, 1});
    }

    for (int i = 0, x, y; i < T; i++) {
        cin >> x >> y;
        points.push_back({x, y, -1});
    }

    int n = P + T;

    if (n == 1) {
        cout << max(points[0][2], 0ll) << endl;
        return 0;
    }

    sort(points.begin(), points.end(), [](arr &a, arr &b) {
        return cross(a, b) > 0;
    });

    int dp[111][111];
    int val[111][111];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            val[i][j] = 0;
            for (int k = 0; k < n; k++) {
                if (point_in_triangle(points[k], points[i], points[j], {0, 0, 0})) {
                    val[i][j] += points[k][2];
                }
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            dp[i][j] = 0;
            for (int k = 0; k < j; k++) {
                if (cross(sub(points[i], points[j]), sub(points[k], points[j])) > 0) {
                    dp[i][j] = max(dp[i][j], dp[j][k]);
                }
            }
            dp[i][j] += val[i][j] + (int) points[j][2];
            ans = max(ans, dp[i][j] + (int) points[i][2]);
        }
    }

    cout << ans << endl;

    return 0;
}

