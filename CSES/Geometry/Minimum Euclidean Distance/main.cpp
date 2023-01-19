// ﷽
#include <bits/stdc++.h>
#include <random>

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
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
        return false;
    return true;
}

pair<complex<double>, double> circle3p(point a, point b, point c) {
    complex<double> A = complex<double>(a.real(), a.imag());
    complex<double> B = complex<double>(b.real(), b.imag());
    complex<double> C = complex<double>(c.real(), c.imag());
    complex<double> ABmid = complex<double>((A.real() + B.real()) / 2.0, (A.imag() + B.imag()) / 2.0);
    complex<double> BCmid = complex<double>((C.real() + B.real()) / 2.0, (C.imag() + B.imag()) / 2.0);
    complex<double> ABnorm = complex<double>((A - B).imag(), -(A - B).real());
    complex<double> BCnorm = complex<double>((B - C).imag(), -(B - C).real());
    complex<double> center;
    bool valid = intersection(ABmid, ABmid + ABnorm, BCmid, BCmid + BCnorm, center);
    assert(valid);
    double r = length(A - center);
    return {center, r};
}

bool inside_circle(point p, vector<point> cir) {
    if (cir.size() == 0) return false;
    if (cir.size() == 1) return same_vec(p, cir[0]);
    double r;
    complex<double> c;

    if (cir.size() == 2) {
        c = complex<double>(cir[0].X + cir[1].X, cir[0].Y + cir[1].Y);
        c.real(c.X / 2), c.imag(c.Y / 2);
        r = length(cir[0] - cir[1]) / 2;
    } else {
        auto temp = circle3p(cir[0], cir[1], cir[2]);
        c = temp.first, r = temp.second;
    }

    return length(complex<double>(p.X, p.Y) - c) <= r;
}

vector<point> welzl(vector<point> &points, int i, vector<point> cir) {
    if (cir.size() == 3 || i == 0) return cir;
    cir = welzl(points, i - 1, cir);
    if (inside_circle(points[i - 1], cir))
        return cir;
    cir.push_back(points[i - 1]);
    return welzl(points, i - 1, cir);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, x, y;
    cin >> n;
    vector<point> points(n);
    for (int i = 0; i < n; i++)
        cin >> x >> y, points[i] = point(x, y);

    shuffle(all(points), default_random_engine());

    auto cir = welzl(points, n, {});
    long long ans = 1e18;
    for (int i = 0; i < (int) cir.size(); i++)
        for (int j = i + 1; j < (int) cir.size(); j++)
            ans = min(ans, norm(cir[i] - cir[j]));

    cout << ans << endl;

    return 0;
}
