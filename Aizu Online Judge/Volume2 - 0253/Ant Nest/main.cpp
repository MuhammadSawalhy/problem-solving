#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);

#define x first
#define y second

using pt = pair<double, double>;
using line = pair<pt, pt>;

pt operator-(const pt &a, const pt &b) { return pt(a.x - b.x, a.y - b.y); }
pt operator+(const pt &a, const pt &b) { return pt(a.x + b.x, a.y + b.y); }

pt rotate(pt p, double rad) {
    return pt{p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad)};
}

double dot(pt a, pt b) { return a.x * b.x + a.y * b.y; }
double cross(pt a, pt b) { return a.x * b.y - a.y * b.x; }

bool intersection(pt a, pt b, pt c, pt d, pt &inter) {
    auto d1 = cross(a - b, d - c);
    auto d2 = cross(a - c, d - c);
    if (fabs(d1) <= 0) return false;
    auto t1 = d2 / d1;
    pt diff = (b - a);
    inter = a + pt{diff.first * t1, diff.second * t1};
    return true;
}

vector<pt> cut(const vector<pt> &p, const line &l, double h) {
    int n = p.size();
    vector<pt> new_polygon;
    bool has_intersection = false;
    bool active = true;

    pt diff = (l.second - l.first);
    double len = sqrtl(diff.x * diff.x + diff.y * diff.y);
    pt perp = rotate((pt{diff.x / len, diff.y / len}), PI / 2);
    pt u{perp.x * h, perp.y * h};

    line newl = line(l.first + u, l.second + u);

    for (int i = 0; i < n; i++) {
        pt cur = p[i];
        pt next = p[(i + 1) % n];
        if (cur.x == next.x && cur.y == next.y) continue;
        pt inter;

        double v1 = cross(newl.second - newl.first, cur - newl.first);
        double v2 = cross(newl.second - newl.first, next - newl.first);

        if (active) {
            new_polygon.push_back(cur);
        }

        if (v1 * v2 < 0 && intersection(newl.first, newl.second, cur, next, inter)) {
            if (cross(next - cur, newl.second - newl.first) < 0) {
                active = false;
            } else if (cross(next - cur, newl.second - newl.first) > 0) {
                if (!has_intersection) new_polygon.clear();
                active = true;
            }

            new_polygon.push_back(inter);
            has_intersection = true;
        }
    }

    return new_polygon;
}

double calc_min_area(double h, const vector<pt> &p) {
    double min_area = 1e9;
    int n = p.size();
    for (int i = 0; i < n; i++) {
        auto cut_p = cut(p, line(p[i], p[(i + 1) % n]), h);
        double area = 0;
        for (int j = 0; j < cut_p.size(); j++) {
            area += cross(cut_p[j], cut_p[(j + 1) % cut_p.size()]);
        }
        min_area = min(min_area, fabs(area) / 2);
    }
    return min_area;
}

int n, d, v;
void solve() {
    vector<pt> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    double l = 0, r = 1e4 + 1;

    for (int iter = 0; iter < 100; iter++) {
        double h = (l + r) / 2;
        double min_vol = calc_min_area(h, p) * d;
        if (min_vol >= v) {
            r = h;
        } else {
            l = h;
        }
    }

    cout << fixed << l << endl;
}

int main(int argc, char **argv) {
    cin.tie(0)->sync_with_stdio(false);

    while (cin >> n >> d >> v, n) {
        solve();
    }

    return 0;
}
