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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;

    while (cin >> n, n) {
        vector<point> vert(n);
        for (int i = 0, x, y; i < n; i++)
            cin >> x >> y, vert[i] = point(x, y);

        long long a = 0;
        long long b = 0;

        vert.push_back(vert[0]);
        for (int i = 0; i < n; i++) {
            a += cp(vert[i], vert[i + 1]);
            b += __gcd(abs(vert[i].real() - vert[i + 1].real()), abs(vert[i].imag() - vert[i + 1].imag()));
        }

        debug(a, b);

        a = abs(a);
        // a = 2 * (i + b / 2 - 1) = 2 * i + b - 2
        cout << (a - b + 2) / 2 << endl;
    }

    return 0;
}
