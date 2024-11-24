// ﷽
#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pii pair<int, int>
#define vi vector<int>
#define all(v) v.begin(), v.end()

struct PointGenerator {
    set<pii> points; // To store unique points

    // Check if three points are collinear
    bool are_collinear(pii a, pii b, pii c) {
        return (b.first - a.first) * (c.second - a.second) == (b.second - a.second) * (c.first - a.first);
    }

    // Generate a unique non-collinear point
    pii generate_non_collinear_point() {
        while (true) {
            int x = rnd.next(1, 10);
            int y = rnd.next(1, 10);
            pii new_point = {x, y};

            // Check if the new point is unique and non-collinear with existing points
            bool is_valid = true;
            for (auto p1 : points) {
                for (auto p2 : points) {
                    if (p1 != p2 && are_collinear(p1, p2, new_point)) {
                        is_valid = false;
                        break;
                    }
                }
                if (!is_valid) break;
            }

            if (is_valid && points.count(new_point) == 0) {
                points.insert(new_point);
                return new_point;
            }
        }
    }

    // Generate `count` non-collinear points
    vector<pii> generate_points(int count) {
        vector<pii> result;
        for (int i = 0; i < count; ++i) {
            result.push_back(generate_non_collinear_point());
        }
        return result;
    }
};

int32_t main(int32_t argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = rnd.next(0, 5);
    int q = rnd.next(0, 5);

    PointGenerator generator;

    if (n + q == 0) n++;

    auto main_points = generator.generate_points(n + q);

    // Print `n` and `q`
    cout << n << " " << q << "\n";

    // Print the main points
    for (auto [x, y] : main_points) {
        cout << x << " " << y << "\n";
    }

    return 0;
}

