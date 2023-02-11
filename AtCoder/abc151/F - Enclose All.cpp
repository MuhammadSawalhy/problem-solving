// ﷽
#include <complex>
#include <iostream>
#include <random>
#include <vector>
#include <assert.h>
#include <iomanip>

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
const double EPS = 0;

typedef complex<long long> point;

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

bool intersection(complex<double> a, complex<double> b, complex<double> c, complex<double> d, complex<double> &inter) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS) return false;
    double t1 = d2 / d1, t2 = d3 / d1;
    inter = a + (b - a) * t1;
    return true;
}

pair<complex<double>, double> circle3p(point a, point b, point c) {
    complex<double> A = complex<double>(a.X, a.Y);
    complex<double> B = complex<double>(b.X, b.Y);
    complex<double> C = complex<double>(c.X, c.Y);
    complex<double> ABmid = (A + B) / 2.0, BCmid = (B + C) / 2.0;
    complex<double> ABnorm = complex<double>((A - B).Y, -(A - B).X);
    complex<double> BCnorm = complex<double>((B - C).Y, -(B - C).X);
    complex<double> center;
    bool valid = intersection(ABmid, ABmid + ABnorm, BCmid, BCmid + BCnorm, center);
    assert(valid);
    double r = length(A - center);
    return {center, r};
}

pair<complex<double>, double> get_circle(vector<point> cir) {
    double r;
    complex<double> c;

    if (cir.size() == 1) {
        c = complex<double>(cir[0].X, cir[0].Y);
        r = 0;
    }
    if (cir.size() == 2) {
        c = complex<double>(cir[0].X + cir[1].X, cir[0].Y + cir[1].Y);
        c.real(c.X / 2), c.imag(c.Y / 2);
        r = length(cir[0] - cir[1]) / 2;
    } else {
        assert(cir.size() == 3);
        return circle3p(cir[0], cir[1], cir[2]);
    }

    return {c, r};
}

bool inside_circle(point p, vector<point> cir) {
    if (cir.size() == 0) return false;
    if (cir.size() == 1) return same_vec(p, cir[0]);
    auto [c, r] = get_circle(cir);
    return cmp(length(complex<double>(p.X, p.Y) - c), r) != 1;// lte (<=)
}

vector<point> welzl(vector<point> &points, int i = 0, vector<point> cir = {}) {
    if (cir.size() == 3 || i == points.size()) return cir;
    auto new_cir = welzl(points, i + 1, cir);
    if (inside_circle(points[i], new_cir))
        return new_cir;
    cir.push_back(points[i]);
    return welzl(points, i + 1, cir);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> points;
    for (int i = 0, x, y; i < n; i++)
        cin >> x >> y, points.push_back(point(x, y));

    shuffle(all(points), default_random_engine());

    auto [c, r] = get_circle(welzl(points));
    cout << setprecision(17) << r << endl;

    return 0;
}
