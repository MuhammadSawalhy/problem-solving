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
const double EPS = 1e-20;

typedef complex<double> point;

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
    auto d = dp(a - c, b - c);
    return cmp(d * d, norm(a - c) * norm(b - c)) == 0 && d <= EPS;
}

int point_in_polygon(point p, vector<point> &polygon) {
    polygon.push_back(polygon[0]);
    int wn = 0, n = polygon.size();
    for (int i = 1; i < n; i++) {
        if (between(polygon[i], polygon[i - 1], p)) return polygon.pop_back(), 0;
        if ((p.Y < polygon[i].Y) != (p.Y < polygon[i - 1].Y)) {
            wn += polygon[i].Y > polygon[i - 1].Y && cp(polygon[i - 1] - p, polygon[i] - p) > EPS;
            wn -= polygon[i].Y < polygon[i - 1].Y && cp(polygon[i] - p, polygon[i - 1] - p) > EPS;
        }
    }
    polygon.pop_back();
    return wn == 0 ? -1 : 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<point> polys[n];

        int id;
        string s;
        double x, y;
        map<int, int> ids;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            istringstream is(s);
            is >> id;
            ids[i] = id;
            while (is >> x >> y)
                polys[i].push_back(point(x, y));
        }

        vector<double> area(n);
        for (int i = 0; i < n; i++) {
            int sz = (int) polys[i].size();
            for (int j = 0; j < sz; j++) {
                area[i] += cp(polys[i][j], polys[i][(j + 1) % sz]);
            }
            area[i] = abs(area[i]);
        }

        vector<int> order(n);
        iota(all(order), 0);
        sort(all(order), [&](int l, int r) { return area[l] > area[r]; });

        int q;
        cin >> q;
        vector<pair<int, int>> ans;
        while (q--) {
            cin >> id >> x >> y;
            auto p = point(x, y);
            int container = 0;
            for (int i: order) {
                if (point_in_polygon(p, polys[i]) != -1) {
                    container = ids[i];
                }
            }
            ans.push_back({id, container});
        }

        sort(all(ans));
        for (auto [i, j]: ans)
            cout << i << " " << j << endl;

        if (t)
            cout << endl;
    }

    return 0;
}
