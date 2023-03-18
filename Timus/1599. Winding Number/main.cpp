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
template<typename T> bool eq0(T f) { return eq(f, (T)0) == 0; }
// clang-format on

bool between(point a, point b, point c) {
    long long d = dp(a - c, b - c);
    return d * d == norm(a - c) * norm(b - c) && d <= EPS;
}

int point_in_polygon(point p,vector<point> &polygon) {
    polygon.push_back(polygon[0]);
    int wn = 0, n = polygon.size();
    for (int i = 1; i < n; i++) {
        if (between(polygon[i], polygon[i - 1], p)) return polygon.pop_back(), -1e9;
        if ((p.Y < polygon[i].Y) != (p.Y < polygon[i - 1].Y)) {
            wn += polygon[i].Y > polygon[i - 1].Y && cp(polygon[i - 1] - p, polygon[i] - p) > EPS;
            wn -= polygon[i].Y < polygon[i - 1].Y && cp(polygon[i] - p, polygon[i - 1] - p) > EPS;
        }
    }
    polygon.pop_back();
    return wn;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    vector<point> poly(n);

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        poly[i] = point(x, y);
    }

    int m;
    cin >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        int wn = point_in_polygon(point(x, y), poly);
        if (wn == -1e9)
            cout << "EDGE" << endl;
        else
            cout << wn << endl;
    }


    return 0;
}
