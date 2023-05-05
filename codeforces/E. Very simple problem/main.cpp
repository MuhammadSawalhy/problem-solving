// ﷽
// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...)      0
#define debug_itr(...)  0
#define debug_bits(...) 0
#endif

#define ll     long long
#define int    long long
#define all(v) v.begin(), v.end()

namespace Geometry
{

using T = long long;
const T EPS = 0;
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
    long double ang(bool pos = true) const {
        auto a = atan2l(y, x);
        if (pos && a < 0) a += PI * 2;
        return a;
    }

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
    bool operator==(const Line &l) const { return iseq0((a - b).cross(l.a - l.b)); };
};

struct Ray : public Segment {
    Ray() {}
    Ray(pt a, pt b) : Segment(a, b) {}
    bool operator==(const Ray &r) const { return a == r.a && slope(a, b, false) == slope(r.a, r.b, false); };
};

struct Polygon {
    int n;
    vector<pt> vert;
    Polygon() = default;
    Polygon(int n) : n(n) { vert.resize(n); }
    Polygon(vector<pt> &vert) : vert(vert), n(vert.size()) {}

    T area2() const {
        T a = 0;
        for (int i = 2; i < n; i++)
            a += vert[0].cross(vert[i], vert[i - 1]);
        return abs(a);
    }

    long double area() const { return area2() / 2.0; };
};

bool parallel(const Line &a, const Line &b) { return (a.b - a.a).cross(b.b - b.a) == 0; }
bool orthogonal(const Line &a, const Line &b) { return (a.a - a.b).dot(b.a - b.b) == 0; }

bool intersect(const Line &l, const Line &m) { return !parallel(l, m); }
bool intersect(const pt &p, const Segment &s) { return ccw(s.a, s.b, p) == 0; }
bool intersect(const pt &p, const Line &l) { return abs(ccw(l.a, l.b, p)) != 1; }
bool intersect(const Segment &s, const Line &l) { return ccw(l.a, l.b, s.a) * ccw(l.a, l.b, s.b) != 1; }
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

bool intersection(pt a, pt b, pt c, pt d, pt &inter) {
    assert(is_floating_point_v<T>);
    long double d1 = (a - b).cross(d - c);
    long double d2 = (a - c).cross(d - c);
    if (fabs(d1) <= EPS) return false;
    long double t1 = d2 / d1;
    inter = a + (b - a) * t1;
    return true;
}

template<typename T, typename V>
bool intersection(const T &l, const V &m, pt &inter) {
    if (!intersect(l, m)) return false;
    return intersection(l.a, l.b, m.a, m.b, inter);
}

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

    friend bool intersect(const pt &p, const Circle &c) { return islte((p - c.c).norm(), c.r * c.r); }
    friend ostream &operator<<(ostream &os, const Circle &c) {
        return os << "c{" << c.c << ", " << c.r << "}";
    }
};

int point_in_triangle(pt a, pt b, pt c, pt point) {
    // point is on an edge or all are either 1 or -1
    int x = ccw(a, b, point), y = ccw(b, c, point), z = ccw(c, a, point);
    if (sign(x) == sign(y) && sign(y) == sign(z)) return 1;
    if (x * y * z == 0) return 0;
    return -1;
}

int point_in_circle(const pt &p, const vector<pt> &cir) {
    if (cir.size() == 0) return -1;
    auto c = Circle(cir);
    if (iseq((p - c.c).norm(), c.r * c.r)) return 0;
    if (intersect(p, c)) return 1;
    return -1;
}

int point_in_polygon(const pt &p, const vector<pt> &polygon) {
    int wn = 0, n = polygon.size();
    for (int i = 0, j = 1; i < n; i++, j++, j %= n) {
        if (ccw(polygon[j], polygon[i], p) == 0) return 0;
        if ((p.y < polygon[j].y) != (p.y < polygon[i].y)) {
            wn += polygon[j].y > polygon[i].y && ccw(p, polygon[i], polygon[j]) == 1;
            wn -= polygon[j].y < polygon[i].y && ccw(p, polygon[j], polygon[i]) == 1;
        }
    }
    return wn == 0 ? -1 : 1;
}

int ray_and_polygon(const Ray &r, const Polygon &polygon) {
    // NOTE: Should be a good ray (a != b),
    // and non-degenerate polygon with no duplicated points
    int n = polygon.n, ans = -1;
    for (int i = 0, j = 1, k = 2; i < n; i++, j++, k++, j %= n, k %= n) {
        if (!intersect(Segment(polygon.vert[i], polygon.vert[j]), r)) continue;
        auto x = r.a.cross(r.b, polygon.vert[i]);
        auto y = r.a.cross(r.b, polygon.vert[j]);
        auto z = r.a.cross(r.b, polygon.vert[k]);
        if (x == 0) ans = 0; // Maybe tangent
        else if (y == 0) {
            // (the ray splits an internal angle)
            // Entering from a vertex
            if (sign(x) * sign(z) == -1) return 1;
        } else return 1; // Entering from an edge
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
            while (sz >= 2 && iseq0(points[i].cross(nodup[sz - 1], nodup[sz - 2])))
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
        if (point_in_circle(points[i], new_cir) != -1)
            return new_cir;
        cir.push_back(points[i]);
        return go(i + 1, cir);
    }
};

}; // namespace Geometry

using namespace Geometry;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<pt> convex(n);
    for (auto &p: convex)
        cin >> p;

    int t;
    cin >> t;
    while (t--) {
        pt p;
        cin >> p;

        int state = point_in_polygon(p, convex);

        if (state != 1) {
            cout << "0\n";
            continue;
        }

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            int s = i, e = i - 1 + n;
            while (e - s > 1) {
                int mid = (s + e) / 2;
                if (ccw(convex[i], convex[(mid) % n], p) != -1) {
                    e = mid;
                } else {
                    s = mid;
                }
            }
            int x = max(0ll, (e - i - 1 + n) % n);
            cnt += (x) * (x - 1) / 2;
        }

        cout << (n * (n - 1) * (n - 2) / 6) - cnt << '\n';
    }

    return 0;
}
