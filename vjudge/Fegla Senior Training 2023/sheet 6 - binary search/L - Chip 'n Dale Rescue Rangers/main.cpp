// ﷽
#include <bits/stdc++.h>

using namespace std;

#ifdef SAWALHY
#include "debug.hpp"
#else
#define debug(...) 0
#define debug_itr(...) 0
#define debug_bits(...) 0
#endif

#define int long long
#define ll long long
#define all(v) v.begin(), v.end()
#define double long double
#define ld double

const double PI = acos(-1.0);
const double EPS = 0;

typedef complex<double> point;

// clang-format off
#define X                       real()
#define Y                       imag()
#define ang(v)                  (atan2((v).Y, (v).X))
#define length(v)               (hypotl((v).Y, (v).X))
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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int x, y, vmax, t;
    point start, dest, w1, w2;
    cin >> x >> y;
    start = point(x, y);
    cin >> x >> y;
    dest = point(x, y);
    cin >> vmax >> t;
    cin >> x >> y;
    w1 = point(x, y);
    cin >> x >> y;
    w2 = point(x, y);

    auto check = [&](ld time) {
        ld t1 = min((ld)1.0 * t, time), t2 = time - t1;
        point s = start;
        s += w1 * t1 + w2 * t2;
        if (length(dest - s) / vmax <= time) return true;
        return false;
    };

    ld s = 0, e = 1e18;
    int steps = 3000;
    while (steps--) {
        ld m = (s + e) / 2;
        if (check(m)) {
            e = m;
        } else {
            s = m;
        }
    }

    cout << fixed << setprecision(17) << e;

    return 0;
}
