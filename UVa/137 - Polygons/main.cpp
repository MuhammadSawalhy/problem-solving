// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()

const double PI = acos(-1.0);
const double EPS = 1e-10;

typedef complex<double> point;

// clang-format off
#define X                       real()
#define Y                       imag()
#define ang(v)                  (atan2((v).Y, (v).X))
#define length(v)               (hypot((v).Y, (v).X))
#define normalize(v)            ((v) / length(v))
#define same_vec(p1,p2)         (dp(vec(p1,p2),vec(p1,p2)) <= EPS)
#define vec(a,b)                ((b)-(a))
#define dp(a,b)                 ((conj(a)*(b)).real())    // a*b cos(T), if zero -> prep
#define cp(a,b)                 ((conj(a)*(b)).imag())    // a*b sin(T), if zero -> parllel
#define rotate(p,ang)           ((p)*exp(point(0,ang)))
#define rotate_about(p,a,ang)   (rotate(vec(a,p),ang)+a)
#define reflect_about(v,a,b)    (conj(vec(a,v)/vec(a,b))*vec(a,b)+a)
template<typename T> int cmp(T f, T s) { return f - s > EPS ? 1 : f - s < -EPS ? -1 : 0; };
template<typename T> bool eq(T f, T s) { return cmp(f, s) == 0; }
template<typename T> bool eq0(T f) { return eq(f, (T)0) == 0; }
// clang-format on
int n, m;

bool between(point a, point b, point c) {
    long long d = dp(a - c, b - c);
    return d * d == norm(a - c) * norm(b - c) && d <= EPS;
}

int point_in_polygon(point p, vector<point> &polygon) {
    polygon.push_back(polygon[0]);
    int wn = 0, n = polygon.size();
    for (int i = 1; i < n; i++) {
        if (between(polygon[i], polygon[i - 1], p)) return polygon.pop_back(), 0;
        if ((p.Y < polygon[i].Y) != (p.Y < polygon[i - 1].Y)) {
            wn += polygon[i].Y > polygon[i - 1].Y && cp(polygon[i - 1] - p, polygon[i] - p) > EPS;
            wn -= polygon[i].Y < polygon[i - 1].Y && cp(polygon[i] - p, polygon[i - 1] - p) > EPS;
        }
    }
    polygon.pop_back();
    return wn == 0 ? -1 : 1;
}

bool intersection(point a, point b, point c, point d, point &inter) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS) return false;
    double t1 = d2 / d1, t2 = d3 / d1;
    inter = a + (b - a) * t1;
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
        return false;
    return true;
}

vector<point> sort_cw(vector<point> vv) {
    vector<point> v;

    for (int i = 0; i < (int)vv.size(); i++) {
         bool ok = true;
         for (int j = 0; j < (int)v.size(); j++) {
            if (same_vec(vv[i], v[j])) {
                ok = false;
            }
         }
        if (ok)
            v.push_back(vv[i]);
    }

    int s = v.size();
    for (int i = 1; i < s; i++) {
        int x = cmp(v[i].X, v[0].X), y = cmp(v[i].Y, v[0].Y);
        if ((y == 0 && x == -1) || y == -1) {// v[i] is smaller than v[0]
            swap(v[0], v[i]);
        }
    }

    sort(v.begin() + 1, v.end(), [&](point l, point r) {
        return cp(l - v[0], r - v[0]) < EPS;
    });

    return v;
}

vector<point> get_intersection(vector<point> poly[]) {
    vector<point> inter;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < (int) poly[i].size(); j++) {
            if (point_in_polygon(poly[i][j], poly[i ^ 1]) != -1)
                inter.push_back(poly[i][j]);
        }
    }

    point inter_point;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (intersection(poly[0][i], poly[0][i + 1], poly[1][j], poly[1][j + 1], inter_point)) {
                inter.push_back(inter_point);
            }
        }
    }

    if (!inter.size())
        return {};

    return sort_cw(inter);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (true) {
        scanf("%lld", &n);
        if (n == 0) break;
        vector<point> poly[2], intersection;
        for (int i = 0, x, y; i < n; i++) {
            scanf("%lld%lld", &x, &y);
            poly[0].push_back(point(x, y));
        }

        scanf("%lld", &m);
        for (int i = 0, x, y; i < m; i++) {
            scanf("%lld%lld", &x, &y);
            poly[1].push_back(point(x, y));
        }

        poly[0].push_back(poly[0][0]);
        poly[1].push_back(poly[1][0]);

        double a1 = 0, a2 = 0, ai = 0, ans;
        for (int i = 0; i < n; i++)
            a1 += cp(poly[0][i], poly[0][i + 1]);
        for (int i = 0; i < m; i++)
            a2 += cp(poly[1][i], poly[1][i + 1]);
        intersection = get_intersection(poly);
        if (intersection.size()) {
            intersection.push_back(intersection[0]);
            for (int i = 0; i < (int) intersection.size(); i++)
                ai += cp(intersection[i], intersection[i + 1]);
        }
        ans = abs(a1) / 2.0 + abs(a2) / 2.0 - abs(ai);
        printf("%8.2f", ans);
    }

    printf("\n");

    return 0;
}
