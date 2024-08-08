// ﷽
// https://codeforces.com/gym/105141/problem/C

#include <bits/stdc++.h>
#include <cmath>
#pragma GCC optimize("Ofast")
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
#define sz(v) (int) (v).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define minit(v, x...) v = min({v, x})
#define maxit(v, x...) v = max({v, x})

template<class T>
using rpq = priority_queue<T, vector<T>, greater<T>>;

namespace Geometry
{

typedef long double ld;
typedef long double T;
const T EPS = 1e-8;
const double PI = acos(-1.0);

template<typename T, typename V>
int cmp(T a, V b) { return (a -= b) < -EPS ? -1 : (a > EPS ? 1 : 0); }
template<typename T, typename V>
bool iseq(T a, V b) { return cmp(a, b) == 0; }
template<typename T>
bool iseq0(T a) { return cmp(a, 0) == 0; }
template<typename T, typename V>
bool islte(T a, V b) { return cmp(a, b) != 1; }
template<typename T, typename V>
bool isgte(T a, V b) { return cmp(a, b) != -1; }
template<typename T, typename V>
bool islt(T a, V b) { return cmp(a, b) == -1; }
template<typename T, typename V>
bool isgt(T a, V b) { return cmp(a, b) == 1; }
template<typename T>
int sign(T val) { return cmp(val, 0); }

enum PointState { OUT,
                  IN,
                  ON };

template<typename T>
struct Point {
    T x, y;

    Point() {}
    Point(T _x, T _y) : x(_x), y(_y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator/(T denom) const { return Point(x / denom, y / denom); }
    Point operator*(T scaler) const { return Point(x * scaler, y * scaler); }

    T dot(const Point &p) const { return x * p.x + y * p.y; }
    T cross(const Point &p) const { return x * p.y - y * p.x; }
    T dot(const Point &a, const Point &b) const { return (a - *this).dot(b - *this); }
    T cross(const Point &a, const Point &b) const { return (a - *this).cross(b - *this); }
    T norm() const { return dot(*this); }

    long double len() const { return sqrtl(dot(*this)); }
    long double ang(bool positive = true) const {
        auto a = atan2l(y, x);
        if (positive && a < 0) a += PI * 2;
        return a;
    }

    long double ang(const Point &p, bool positive = true) const {
        auto a = asinl(cross(p) / len() / p.len());
        if (positive && a < 0) a += PI * 2;
        return a;
    }

    Point scale(long double l) {
        auto a = ang();
        return {T(l * cos(a)), T(l * sin(a))};
    };

    Point rotate(const Point &p, long double a) { return (*this - p).rotate(a) + p; }
    Point rotate(long double angle) {
        auto l = len(), a = ang();
        return Point(l * cos(a + angle), l * sin(a + angle));
    }

    bool operator==(const Point &p) const { return (*this - p).norm() <= EPS; }
    bool operator!=(const Point &p) const { return !(*this == p); }
    bool operator<(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
    friend ostream &operator<<(ostream &os, const Point &p) { return os << '(' << p.x << ',' << p.y << ')'; }
    friend istream &operator>>(istream &is, Point &p) { return is >> p.x >> p.y; }
};

typedef Point<T> pt;

int ccw(const pt &a, pt b, pt c) {
    if (a == b) return (a == c ? 0 : +3); // same point or different
    b = b - a, c = c - a;
    if (sign(b.cross(c)) == +1) return +1;        // "COUNTER_CLOCKWISE"
    if (sign(b.cross(c)) == -1) return -1;        // "CLOCKWISE"
    if (sign(b.dot(c)) == -1) return +2;          // "ON_RAY_b_a)"
    if (cmp(b.norm(), c.norm()) == -1) return -2; // "ON_RAY_a_b"
    return 0;                                     // "ON_SEGMENT"
}

bool colinear(const pt &a, const pt &b, const pt &c) {
    return abs(ccw(a, b, c)) != 1;
}

pt slope(pt a, pt b, bool change_direction = true) {
    assert(is_integral_v<T>);
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    if (dx == 0 && dy == 0) return pt(0, 0);
    long long g = gcd(abs(dy), abs(dy));
    dx /= g, dy /= g;
    if (change_direction) {
        if (dx < 0) dy *= -1, dx *= -1;
        if (dx == 0) dy = abs(dy);
    }
    return pt(dx, dy);
}

struct Segment {
    pt a, b;
    Segment() {}
    Segment(pt a, pt b) : a(a), b(b) {}
    bool operator==(const Segment &s) const { return a == s.a ? b == s.b : a == s.b && b == s.a; };
    friend istream &operator>>(istream &is, Segment &s) { return is >> s.a >> s.b; }
    friend ostream &operator<<(ostream &os, const Segment &s) {
        return os << "{" << s.a << ", " << s.b << "}";
    }
};

struct Line : public Segment {
    Line() {}
    Line(pt a, pt b) : Segment(a, b) {}
    Line(pt a, long double slope) : Segment(a, a + pt(1, 0).rotate(slope)) {}
    bool operator==(const Line &l) const { return iseq0((a - b).cross(l.a - l.b)); };
};

struct Ray : public Segment {
    Ray() {}
    Ray(pt a, pt b) : Segment(a, b) {}
    bool operator==(const Ray &r) const { return a == r.a && slope(a, b, false) == slope(r.a, r.b, false); };
};

struct Polygon {
    int n;
    vector<pt> verts;
    Polygon() = default;
    Polygon(int n) : n(n) { verts.resize(n); }
    Polygon(vector<pt> &vert) : verts(vert), n(vert.size()) {}

    T area2() const {
        T a = 0;
        for (int i = 2; i < n; i++)
            a += verts[0].cross(verts[i], verts[i - 1]);
        return abs(a);
    }

    long double area() const { return area2() / 2.0; };

    void no_collinear() {
        vector<pt> v;
        for (int i = 0; i <= n; i++) {
            while (v.size() > 1 && colinear(v.back(), v.end()[-2], verts[i % n]))
                v.pop_back();
            v.push_back(verts[i % n]);
        }
        v.pop_back();
        n = v.size();
        verts = v;
        assert(n > 2);
    }

    void ensure_ccw() {
        start_bottom_left();
        if (ccw(verts[0], verts[1], verts.back()) == -1)
            reverse(verts.begin() + 1, verts.end());
    }

    void start_bottom_left() {
        int pos = 0; // most left-bottom point
        for (int i = 1; i < n; i++)
            if (verts[i] < verts[pos])
                pos = i;
        rotate(verts.begin(), verts.begin() + pos, verts.end());
    }
};

bool parallel(const Line &a, const Line &b) { return (a.b - a.a).cross(b.b - b.a) == 0; }
bool orthogonal(const Line &a, const Line &b) { return (a.a - a.b).dot(b.a - b.b) == 0; }

bool intersect(const Line &l, const Line &m) { return !parallel(l, m); }

bool intersect(const pt &p, const Segment &s) { return ccw(s.a, s.b, p) == 0; }
bool intersect(const Segment &s, const pt &p) { return intersect(p, s); }

bool intersect(const pt &p, const Line &l) { return abs(ccw(l.a, l.b, p)) != 1; }
bool intersect(const Line &l, const pt &p) { return intersect(p, l); }

bool intersect(const Segment &s, const Line &l) { return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) != 1; }
bool intersect(const Line &l, const Segment &s) { return intersect(s, l); }

bool intersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }

bool intersect(const Segment &s, const Ray &r) {
    auto d1 = (s.a - s.b).cross(r.b - r.a),
         d2 = (s.a - r.a).cross(r.b - r.a),
         d3 = (s.a - s.b).cross(s.a - r.a);
    if (abs(d1) <= EPS)
        return r.a.cross(r.b, s.a) == 0 &&
               (r.a.dot(r.b, s.a) >= 0 || r.a.dot(r.b, s.b) >= 0); // NOT BACK
    return sign(d1) * sign(d2) >= 0 && sign(d1) * sign(d3) >= 0 && abs(d2) <= abs(d1);
}

bool intersect(const Ray &r, const Segment &s) { return intersect(s, r); }

template<typename P = pt>
bool intersection(P a, P b, P c, P d, Point<ld> &inter) {
    ld d1 = (a - b).cross(d - c), d2 = (a - c).cross(d - c);
    if (iseq0(d1)) return false;
    return inter = a + (b - a) * (d2 / d1), true;
}

template<typename T, typename V>
bool intersection(const T &l, const V &m, pt &inter) {
    if (!intersect(l, m)) return false;
    return intersection(l.a, l.b, m.a, m.b, inter);
}

// - NOTE: The polygon shouldn't have collinear points.
// - NOTE: First vertex should be the bottom-left, points in ccw order.
vector<pt> intersection(const Polygon &poly, const Line &line) {
    int n = poly.n;
    vector<pt> inter;
    const vector<pt> &verts = poly.verts;

    pt x;
    for (int i = 1; i <= n; i++) {
        int I = i % n, J = i - 1, K = (i - 2 + n) % n;
        if (intersection(line, Segment(verts[I], verts[J]), x)) {
            if (x == verts[I]) continue;
            if (x != verts[J]) {
                inter.push_back(x);
                continue;
            }
            int dir1 = ccw(line.a, line.b, verts[I]);
            int dir2 = ccw(line.a, line.b, verts[K]);
            if (dir1 * dir2 == -1)
                // entering or leaving from a vertex
                inter.push_back(verts[J]);
        } else if (abs(ccw(line.a, line.b, verts[J])) != 1) {
            // side (I, J) is on the line
            bool isWideAngleI = islt(ccw(verts[I], verts[((I + 1) % n)], verts[J]), 0);
            bool isWideAngleJ = islt(ccw(verts[J], verts[I], verts[K]), 0);
            if (isWideAngleI) inter.push_back(verts[I]);
            if (isWideAngleJ) inter.push_back(verts[J]);
            inter.push_back(verts[I]);
            inter.push_back(verts[J]);
        }
    }

    debug(inter);

    // sort in one direction, as if you travel on the line
    // in this direction and see the points one by one
    // NOTE: points may NOT be eaxctly on the line due to precesion errors
    sort(all(inter), [&](pt l, pt r) {
        return sign((line.b - line.a).dot(r - l)) == 1;
    });

    assert(inter.size() % 2 == 0);
    return inter;
};

struct Circle {
    pt c;
    T r;

    Circle() = default;
    Circle(pt c, T r) : c(c), r(r) {}
    Circle(const vector<pt> &p) {
        if (p.size() == 1) c = p[0], r = 0;
        else if (p.size() == 2) {
            c = (p[0] + p[1]) / 2;
            r = (p[0] - c).len();
        } else {
            assert(p.size() == 3);
            *this = Circle(p[0], p[1], p[2]);
        }
    }

    Circle(pt a, pt b, pt c) {
        // if we have a cord in a circle,
        // the perpendicular from the center will pass from the center
        // so we simply solve for the interection of two lines
        auto ABmid = (a + b) / 2.0, BCmid = (b + c) / 2.0;
        auto ABnorm = pt((a - b).y, -(a - b).x);
        auto BCnorm = pt((b - c).y, -(b - c).x);
        bool valid = intersection(
                Line(ABmid, ABmid + ABnorm),
                Line(BCmid, BCmid + BCnorm), this->c);
        assert(valid); // unless at least two points are identical
        r = (a - this->c).len();
    }

    friend ostream &operator<<(ostream &os, const Circle &c) {
        return os << "c{" << c.c << ", " << c.r << "}";
    }
};

PointState point_in_triangle(pt a, pt b, pt c, pt point) {
    int x = ccw(a, b, point), y = ccw(b, c, point), z = ccw(c, a, point);
    if (sign(x) == sign(y) && sign(y) == sign(z)) return IN;
    if (x * y * z == 0) return ON;
    return OUT;
}

PointState point_in_circle(const pt &p, const vector<pt> &cir) {
    if (cir.size() == 0) return OUT;
    auto c = Circle(cir);
    if (iseq((p - c.c).norm(), c.r * c.r)) return ON;
    if (islt((p - c.c).norm(), c.r * c.r)) return IN;
    return OUT;
}

PointState point_in_polygon(const pt &p, const vector<pt> &polygon) {
    int wn = 0, n = polygon.size();
    for (int i = 0, j = 1; i < n; i++, j++, j %= n) {
        if (ccw(polygon[j], polygon[i], p) == 0) return ON;
        if ((p.y < polygon[j].y) != (p.y < polygon[i].y)) {
            wn += polygon[j].y > polygon[i].y && ccw(p, polygon[i], polygon[j]) == 1;
            wn -= polygon[j].y < polygon[i].y && ccw(p, polygon[j], polygon[i]) == 1;
        }
    }
    return wn == 0 ? OUT : IN;
}

PointState ray_and_polygon(const Ray &r, const Polygon &polygon) {
    // NOTE: Should be a good ray (a != b),
    // and non-degenerate polygon with no duplicated points
    int n = polygon.n;
    PointState ans = OUT;
    for (int i = 0, j = 1, k = 2; i < n; i++, j++, k++, j %= n, k %= n) {
        if (!intersect(Segment(polygon.verts[i], polygon.verts[j]), r)) continue;
        auto x = r.a.cross(r.b, polygon.verts[i]);
        auto y = r.a.cross(r.b, polygon.verts[j]);
        auto z = r.a.cross(r.b, polygon.verts[k]);
        if (x == 0) ans = ON; // Maybe tangent
        else if (y == 0) {
            // (the ray splits an internal angle)
            // Entering from a vertex
            if (sign(x) * sign(z) == -1) return IN;
        } else return IN; // Entering from an edge
    }
    return ans;
}

vector<pt> &sort_clock(vector<pt> &points, bool cw = false) {
    int n = points.size();

    // choose the pivot (most bottom-right point)
    for (int i = 1; i < n; i++) {
        auto &l = points[0], &r = points[i];
        int cy = cmp(l.y, r.y), cx = cmp(l.x, r.x);
        if (cy == 0 ? cx == -1 : cy == +1) swap(l, r);
    }

    // sorting with points[0] as pivot
    sort(points.begin() + 1, points.end(),
         [&](pt l, pt r) {
             auto c = ccw(points[0], l, r);
             int cx = cmp(l.x, r.x), cy = cmp(l.y, r.y);
             // closer to bottom-right comes first
             if (abs(c) != 1) return cy == 0 ? cx == 1 : cy == -1;
             return cw ? c == -1 : c == 1;
         });

    return points;
}

// sort a convex polygon cw or ccw with the bottom-right as the pivot
vector<pt> &sort_convex(vector<pt> &points, bool cw = false) {
    int n = points.size();

    // choose the pivot (most bottom-right point)
    for (int i = 1; i < n; i++) {
        auto &l = points[0], &r = points[i];
        int cy = cmp(l.y, r.y), cx = cmp(l.x, r.x);
        if (cy == 0 ? cx == -1 : cy == +1) swap(l, r);
    }

    // sorting with points[0] as pivot
    sort(points.begin() + 1, points.end(),
         [&](pt l, pt r) {
             auto c = ccw(points[0], l, r);
             int cx = cmp(l.x, r.x), cy = cmp(l.y, r.y);

             if (abs(c) != 1) { // collinear
                 if (cw) return cy == 0 ? cx == 1 : cy == 1;
                 else
                     return cy == 0 ? cx == -1 : cy == -1;
             }

             return cw ? c == -1 : c == 1;
         });

    return points;
}

template<typename P = pt>
vector<P> convexhull(vector<P> &p, bool strict = false) {
    int n = p.size(), k = 0, sgn = strict ? 0 : -1;
    if (n <= 2) return p;
    vector<P> ch(2 * n); // CCW
    auto cmp = [](P x, P y) { return (x.x != y.x ? x.x < y.x : x.y < y.y); };
    sort(begin(p), end(p), cmp);
    for (int i = 0; i < n; ch[k++] = p[i++]) // lower hull
        while (k >= 2 && sign((ch[k - 1] - ch[k - 2]).cross(p[i] - ch[k - 1])) <= sgn) --k;
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) // upper hull
        while (k >= t && sign((ch[k - 1] - ch[k - 2]).cross(p[i] - ch[k - 1])) <= sgn) --k;
    ch.resize(k - 1);
    return ch;
}

struct PointInConvex {
    int n;
    vector<pt> seq;
    pt translation;

    PointInConvex(vector<pt> polygon) { prepare_convex_ccw(polygon); }

    void prepare_convex_ccw(vector<pt> &points) {
        // NOTE: the polygon should be strictly convex
        n = points.size();
        int pos = 0; // most left-bottom point
        for (int i = 1; i < n; i++)
            if (points[i] < points[pos])
                pos = i;
        rotate(points.begin(), points.begin() + pos, points.end());

        seq.resize(n);
        for (int i = 0; i < n; i++)
            seq[i] = points[(i + 1) % n] - points[0];
        translation = points[0];
    }

    int check(pt point) {
        point = point - translation;
        if (intersect(point, Segment(pt(0, 0), seq[0]))) return 0;
        if (seq.size() <= 2) return -1;

        int l = 0, r = n - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (sign(seq[mid].cross(point)) != -1)
                l = mid;
            else
                r = mid;
        }

        int ok = point_in_triangle(seq[l], seq[l + 1], pt(0, 0), point);
        if (ok == -1) return -1;
        if (intersect(point, Segment(seq[l], seq[l + 1]))) return 0;
        return 1;
    }
};

struct Welzl {
    vector<pt> points;
    Welzl(vector<pt> &_points) : points(_points) {
        shuffle(all(points), default_random_engine(time(NULL)));
    }

    Circle get_circle() { return Circle(go()); }
    vector<pt> go(int i = 0, vector<pt> cir = {}) {
        if (cir.size() == 3 || i == (int) points.size()) return cir;
        auto new_cir = go(i + 1, cir);
        if (point_in_circle(points[i], new_cir) != OUT)
            return new_cir;
        cir.push_back(points[i]);
        return go(i + 1, cir);
    }
};

}; // namespace Geometry

using namespace Geometry;

void solve() {
    int n;
    long double r, theta;

    cin >> n >> r >> theta;
    vector<Point<ll>> pts(n);
    theta *= PI / 180;

    long double ans = 1e18;

    for (int i = 0; i < n; i++) {
        cin >> pts[i];
    }

    pts = convexhull(pts, true);
    n = sz(pts);

    if (n < 3) {
        cout << r << endl;
        return;
    } else if (n == 3) {
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            auto p = pts[j] - pts[i];
            ans = min(ans, 0.5 * p.len() / tan(theta));
        }
    } else {
        debug(n, pts);
        pt p;
        Line l;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            int k = (i + 2) % n;
            int l = (i + 3) % n;
            if (islte((pts[l] - pts[k]).ang(pts[i] - pts[j]), theta)) {
            }

            auto alpha = PI - theta - (pts[j] - pts[i]).ang(pts[k] - pts[j]);
            if (isgt(alpha, 0))
                minit(ans, (pts[j] + (pts[j] - pts[i]).scale((pts[k] - pts[j]).len() * sin(alpha) / sin(theta))).len());
            else ans = 0;

            alpha = PI - theta - (pts[j] - pts[k]).ang(pts[k] - pts[l]);
            if (isgt(alpha, 0))
                minit(ans, (pts[k] + (pts[k] - pts[l]).scale((pts[k] - pts[j]).len() * sin(alpha) / sin(theta))).len());
            else ans = 0;
        }
    }


    cout << max(ans, r) << endl;
}

int32_t main(int32_t argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cout << setprecision(12) << fixed;

    int t = 1;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
