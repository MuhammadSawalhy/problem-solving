#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define all(x) (x).begin(), (x).end()

#define endl '\n'
#define int ll

namespace Geometry
{

using T = long double;
const T EPS = 0;
const double PI = acos(-1.0);

template<typename T, typename V>
int cmp(T a, V b) { return (a -= b) < -EPS ? -1 : (a > EPS ? 1 : 0); }

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
    T dot(const Point &a, const Point &b) const {
        return (a - *this).dot(b - *this);
    }
    T cross(const Point &a, const Point &b) const {
        return (a - *this).cross(b - *this);
    }
    T norm() const { return dot(*this); }

    long double len() const { return sqrtl(dot(*this)); }
    long double ang(bool pos = true) const {
        auto a = atan2l(y, x);
        if (pos && a < 0) a += PI * 2;
        return a;
    }

    Point rotate(const Point &p, long double a) {
        return (*this - p).rotate(a) + p;
    }

    Point rotate(long double angle) {
        auto l = len(), a = ang();
        return Point(l * cosl(a + angle), l * sinl(a + angle));
    }

    bool operator==(const Point &p) const { return (*this - p).norm() <= EPS; }
    bool operator!=(const Point &p) const { return !(*this == p); }
    bool operator<(const Point &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    friend ostream &operator<<(ostream &os, const Point &p) {
        return os << '(' << p.x << ',' << p.y << ')';
    }
    friend istream &operator>>(istream &is, Point &p) {
        return is >> p.x >> p.y;
    }
} pt;

typedef struct Pointll {
    typedef long long T;
    T x, y;

    Pointll() {}
    Pointll(T _x, T _y) : x(_x), y(_y) {}
    Pointll operator+(const Pointll &p) const { return Pointll(x + p.x, y + p.y); }
    Pointll operator-(const Pointll &p) const { return Pointll(x - p.x, y - p.y); }
    Pointll operator/(T denom) const { return Pointll(x / denom, y / denom); }
    Pointll operator*(T scaler) const { return Pointll(x * scaler, y * scaler); }

    T dot(const Pointll &p) const { return x * p.x + y * p.y; }
    T cross(const Pointll &p) const { return x * p.y - y * p.x; }
    T dot(const Pointll &a, const Pointll &b) const {
        return (a - *this).dot(b - *this);
    }
    T cross(const Pointll &a, const Pointll &b) const {
        return (a - *this).cross(b - *this);
    }
    T norm() const { return dot(*this); }

    long double len() const { return sqrtl(dot(*this)); }
    long double ang(bool pos = true) const {
        auto a = atan2l(y, x);
        if (pos && a < 0) a += PI * 2;
        return a;
    }

    Pointll rotate(const Pointll &p, long double a) {
        return (*this - p).rotate(a) + p;
    }

    Pointll rotate(long double angle) {
        auto l = len(), a = ang();
        return Pointll(l * cosl(a + angle), l * sinl(a + angle));
    }

    bool operator==(const Pointll &p) const { return (*this - p).norm() <= EPS; }
    bool operator!=(const Pointll &p) const { return !(*this == p); }
    bool operator<(const Pointll &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
    friend ostream &operator<<(ostream &os, const Pointll &p) {
        return os << '(' << p.x << ',' << p.y << ')';
    }
    friend istream &operator>>(istream &is, Pointll &p) {
        return is >> p.x >> p.y;
    }
} ptll;

int ccw(const ptll &a, ptll b, ptll c) {
    if (a == b) return (a == c ? 0 : +3); // same point or different
    b = b - a, c = c - a;
    if (sign(b.cross(c)) == +1) return +1;        // "COUNTER_CLOCKWISE"
    if (sign(b.cross(c)) == -1) return -1;        // "CLOCKWISE"
    if (sign(b.dot(c)) == -1) return +2;          // "ON_RAY_b_a"
    if (cmp(b.norm(), c.norm()) == -1) return -2; // "ON_RAY_a_b"
    return 0;                                     // "ON_SEGMENT"
}

}; // namespace Geometry

using namespace Geometry;

void solve() {
    ptll aa, bb, cc, tt;
    int s;
    cin >> aa >> bb >> cc >> tt >> s;

    if (s == 0) {
        swap(aa, cc);
    }

    auto A = ccw(aa, bb, tt);
    auto B = ccw(aa, bb, cc);

    bool can = abs(A * B) == 1 && A == B && sign(bb.dot(tt, aa)) == 1;

    if (!can) {
        cout << "NO" << endl;
        return;
    }

    pt a = pt(aa.x, aa.y);
    pt b = pt(bb.x, bb.y);
    pt c = pt(cc.x, cc.y);
    pt t = pt(tt.x, tt.y);

    a = a - b;
    c = c - b;
    t = t - b;
    b = b - b;

    long double a_ang = a.ang();

    c = c.rotate(-a_ang);
    t = t.rotate(-a_ang);
    a = a.rotate(-a_ang);

    bool isneg = false;

    if (sign(c.y) == -1) {
        isneg = true;
        a.y *= -1;
        b.y *= -1;
        c.y *= -1;
        t.y *= -1;
    }

    cout << "YES" << endl;

    long double ans = t.ang() * 2 - c.ang();

    if (isneg) {
        ans *= -1;
    }

    cout << fixed << setprecision(10) << ans * 180 / PI << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
