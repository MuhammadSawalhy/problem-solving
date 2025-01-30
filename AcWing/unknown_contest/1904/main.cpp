#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

int dist(const Point &a, const Point &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; ++i) cin >> points[i].x >> points[i].y;

    vector<int> prefix(N, 0), suffix(N, 0);
    for (int i = 1; i < N; ++i)
        prefix[i] = prefix[i - 1] + dist(points[i - 1], points[i]);
    for (int i = N - 2; i >= 0; --i)
        suffix[i] = suffix[i + 1] + dist(points[i], points[i + 1]);


    int ans = 1e9;
    for (int i = 1; i < N - 1; ++i) {
        int d = prefix[i - 1] +
                dist(points[i - 1], points[i + 1]) +
                suffix[i + 1];
        ans = min(ans, d);
    }

    cout << ans << endl;
    return 0;
}

