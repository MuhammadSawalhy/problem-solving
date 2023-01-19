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
// clang-format on

vector<point> convexhull(vector<point> points, bool collinear = true) {
    int n = points.size();
    vector<point> hull;

    // choose the pivot
    for (int i = 1; i < n; i++) {
        auto &l = points[0], &r = points[i];
        int cy = cmp(l.Y, r.Y), cx = cmp(l.X, r.X);
        if (cy == 0 ? cx == 1 : cy == 1) swap(l, r);
    }

    // CW sorting with points[0] as pivot
    sort(points.begin() + 1, points.end(),
         [&](auto l, auto r) {
             int c = cp(l - points[0], r - points[0]);
             int cy = cmp(l.Y, r.Y), cx = cmp(l.X, r.X);
             if (eq(c, 0LL)) return cy == 0 ? cx == -1 : cy == -1;
             return c < -EPS;
         });

    for (int i = 0, sz = 0; i < n; i++) {
        if (collinear)
            while (sz > 1 && cp(points[i] - hull[sz - 1], hull[sz - 2] - hull[sz - 1]) > EPS)
                hull.pop_back(), sz--;
        else
            while (sz > 1 && cp(points[i] - hull[sz - 1], hull[sz - 2] - hull[sz - 1]) >= -EPS)
                hull.pop_back(), sz--;
        hull.push_back(points[i]), sz++;
    }

    if (collinear)
        // for the last points that are collinear hull[0], hull[sz - 1]
        for (int i = 0, sz = hull.size(); i < n; i++) {
            if (same_vec(points[i], hull[0]) || same_vec(points[i], hull[sz - 1]))
                continue;
            if (eq(cp(points[i] - hull[0], points[i] - hull[sz - 1]), 0LL))
                hull.push_back(points[i]);
        }

    return hull;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;
    vector<point> points(n);

    int x, y;
    for (int i = 0; i < n; i++)
        cin >> x >> y, points[i] = point(x, y);

    auto ch = convexhull(points, true);

    cout << ch.size() << endl;

    for (int i = 0; i < (int) ch.size(); i++)
        cout << ch[i].X << " " << ch[i].Y << endl;

    return 0;
}
