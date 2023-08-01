// ﷽
#include <bits/stdc++.h>
#include <math.h>
#include <type_traits>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define ll long long
#define all(v) v.begin(), v.end()

namespace Geometry
{

using T = long long;
const T EPS = 0;
const double PI = acos(-1.0);

template<typename T, typename V>
int cmp(T a, V b) { return (a -= b) < -EPS ? -1 : (a > EPS ? 1 : 0); }
template<typename T, typename V>
bool eq(T a, V b) { return cmp(a, b) == 0; }
template<typename T>
bool eq0(T a) { return cmp(a, 0) == 0; }
template<typename T>
int sign(T val) { return cmp(val, 0); }

typedef struct Point {
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
    long double ang() const { return atan2l(x, y); }

    Point rotate(const Point &p, long double a) { return (*this - p).rotate(a) + p; }
    Point rotate(long double angle) {
        auto l = len(), a = ang();
        return Point(l * cos(a + angle), l * sin(a + angle));
    }

    bool operator==(const Point &p) const { return (*this - p).norm() <= EPS; }
    bool operator!=(const Point &p) const { return !(*this == p); }
    bool operator<(const Point &p) const { return x < p.x || (x == p.x && y < p.y); }
    friend ostream &operator<<(ostream &os, const Point &p) { return os << '(' << p.x << ',' << p.y << ')'; }
} pt;

int ccw(const pt &a, pt b, pt c) {
    if (a == b) return (a == c ? 0 : +3); // same point or different
    b = b - a, c = c - a;
    if (sign(b.cross(c)) == +1) return +1;        // "COUNTER_CLOCKWISE"
    if (sign(b.cross(c)) == -1) return -1;        // "CLOCKWISE"
    if (sign(b.dot(c)) == -1) return +2;          // "ONLINE_BACK"
    if (cmp(b.norm(), c.norm()) == -1) return -2; // "ONLINE_FRONT"
    return 0;                                     // "ON_SEGMENT"
}

struct Segment {
    pt a, b;
    Segment() {}
    Segment(pt a, pt b) : a(a), b(b) {}
};

struct Line {
    pt a, b;
    Line() {}
    Line(pt a, pt b) : a(a), b(b) {}
};


struct Circle {
    pt p;
    T r;
    Circle() = default;
    Circle(Point p, T r) : p(p), r(r) {}
};

struct Polygon {
    int n;
    vector<pt> vert;
    Polygon() = default;
    Polygon(vector<pt> &vert) : vert(vert) { n = vert.size(); }

    T area2x() {
        T a = 0;
        for (int i = 2; i < n; i++)
            a += vert[0].cross(vert[i], vert[i - 1]);
        return abs(a);
    }

    long double area() { return area2x() / 2.0; };
};

bool parallel(const Line &a, const Line &b) { return (a.b - a.a).cross(b.b - b.a) == 0; }
bool orthogonal(const Line &a, const Line &b) { return (a.a - a.b).dot(b.a - b.b) == 0; }
bool intersect(const Line &l, const Line &m) { return !parallel(l, m); }
bool intersect(const pt &p, const Segment &s) { return ccw(s.a, s.b, p) == 0; }
bool intersect(const pt &p, const Line &l) { return abs(ccw(l.a, l.b, p)) != 1; }
bool intersect(const Segment &s, const Line &l) { return l.a.cross(l.b, s.a) * l.a.cross(l.b, s.b) <= 0; }
bool intersect(const Segment &s, const Segment &t) { return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0; }

pt intersection(pt a, pt b, pt c, pt d) {
    // NOTE: use T as long double
    // check Dr. Mostafa Saad's Videos
    long double d1 = (a - b).cross(d - c);
    long double d2 = (a - c).cross(d - c);
    // you should check for intersection before calling this
    assert(fabs(d1) > EPS);
    long double t1 = d2 / d1;
    pt inter = a + (b - a) * t1;
    return inter;
}

bool intersection(const Line &l, const Line &m, pt &inter) {
    if (!intersect(l, m)) return false;
    inter = intersection(l.a, l.b, m.a, m.b);
    return true;
}

bool intersection(const Segment &l, const Segment &m, pt &inter) {
    if (!intersect(l, m)) return false;
    inter = intersection(l.a, l.b, m.a, m.b);
    return true;
}

bool intersection(const Segment &s, const Line &l, pt &inter) {
    if (!intersect(s, l)) return false;
    inter = intersection(l.a, l.b, s.a, s.b);
    return true;
}

bool point_in_triangle(pt a, pt b, pt c, pt point) {
    // point is on an edge or all are either 1 or -1
    int x = ccw(a, b, point), y = ccw(b, c, point), z = ccw(c, a, point);
    return x * y * z == 0 || (sign(x) == sign(y) && sign(y) == sign(z));
}

pair<pt, double> circle3p(pt a, pt b, pt c) {
    // NOTE: use T as long double
    // if we have a cord in a circle,
    // the perpendicular from the center will pass from the center
    // so we simply solve for the interection of two lines
    auto ABmid = (a + b) / 2.0, BCmid = (a + c) / 2.0;
    auto ABnorm = pt((a - b).y, -(a - b).x);
    auto BCnorm = pt((b - c).y, -(b - c).x);
    pt center;
    bool valid = intersection(
            Line(ABmid, ABmid + ABnorm),
            Line(BCmid, BCmid + BCnorm), center);
    assert(valid); // unless two points are identical
    double r = (a - center).len();
    return {center, r};
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

vector<pt> convexhull(vector<pt> &p, bool strict = false) {
    int n = p.size(), k = 0, sgn = strict ? 0 : -1;
    if (n <= 2) return p;
    vector<pt> ch(2 * n); // CCW
    auto cmp = [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y < y.y); };
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
        n = points.size();
        int pos = 0; // most left-bottom point
        for (int i = 1; i < n; i++) {
            if (points[i] < points[pos])
                pos = i;
        }
        rotate(points.begin(), points.begin() + pos, points.end());

        // no duplication
        points.push_back(points.front());
        vector<pt> nodup; // no duplications
        for (int i = 0, sz = 0; i < (int) points.size(); i++) {
            while (sz >= 2 && eq0(points[i].cross(nodup[sz - 1], nodup[sz - 2])))
                nodup.pop_back(), sz--;
            nodup.push_back(points[i]), sz++;
        }

        nodup.pop_back();
        points = nodup;
        n = points.size();
        assert(n >= 1);

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

        bool ok = point_in_triangle(seq[l], seq[l + 1], pt(0, 0), point);
        if (!ok) return -1;
        if (intersect(point, Segment(seq[l], seq[l + 1]))) return 0;
        return 1;
    }
};

}; // namespace Geometry

using namespace Geometry;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<pt> points(n);

    for (int i = 0, x, y; i < n; i++)
        cin >> x >> y, points[i] = pt(x, y);

    auto ch = convexhull(points);

    cout << ch.size() << endl;
    for (int i = 0; i < (int) ch.size(); i++)
        cout << ch[i].x << " " << ch[i].y << endl;

    return 0;
}
