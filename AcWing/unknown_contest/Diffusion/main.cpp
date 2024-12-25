#include <bits/stdc++.h>
using namespace std;

struct Point {
    long long x, y;
};

bool are_connected(const Point &a, const Point &b, long long s) {
    return abs(a.x - b.x) + abs(a.y - b.y) <= 2 * s;
}

bool is_connected(const vector<Point> &points, long long s) {
    int n = points.size();
    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;
    int count = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && are_connected(points[u], points[v], s)) {
                visited[v] = true;
                q.push(v);
                count++;
            }
        }
    }

    return count == n;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    long long low = 0, high = 1e9, answer = high;
    while (low <= high) {
        long long mid = (low + high) / 2;

        if (is_connected(points, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;
    return 0;
}

