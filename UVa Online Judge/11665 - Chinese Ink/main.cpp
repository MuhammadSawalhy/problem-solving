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

struct union_find {
    vector<int> rank, parent;
    int forests;

    union_find(int n) {
        forests = n;
        rank = vector<int>(n);
        parent = vector<int>(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    bool connected(int x, int y) { return find(x) == find(y); }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    bool uni(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (rank[y] > rank[x])
            swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        forests--;
        return true;
    }
};

bool between(point a, point b, point c) {
    auto d = dp(a - c, b - c);
    return cmp(d * d, norm(a - c) * norm(b - c)) == 0 && d <= EPS;
}

int point_in_polygon(point p,vector<point> &polygon) {
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

bool intersects(point a, point b, point c, point d) {
    double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
    if (fabs(d1) < EPS)
        return between(a, b, c) || between(a, b, d) || between(c, d, a) || between(c, d, b);  // Parllel || identical
    double t1 = d2 / d1, t2 = d3 / d1;
    if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS || t1 > 1 + EPS)
        return false;
    return true;
}

bool overlap(int i, int j, vector<point> polys[]) {
    int n = polys[i].size(), m = polys[j].size();
    for (int k = 0; k < n; k++) {
        if (point_in_polygon(polys[i][k], polys[j]) != -1) {
            return true;
        }
    }

    for (int k = 0; k < m; k++) {
        if (point_in_polygon(polys[j][k], polys[i]) != -1) {
            return true;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int r = 0; r < m; r++) {
            if (intersects(polys[i][k], polys[i][(k + 1) % n], polys[j][r], polys[j][(r + 1) % m])) {
                return true;
            }
        }
    }

    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    double x, y;
    while (cin >> n, n) {
        vector<point> polys[n];
        string s;
        cin.ignore();
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            istringstream is(s);
            while (is >> x >> y)
                polys[i].push_back(point(x, y));
        }

        union_find uf(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (uf.connected(i, j)) continue;
                if (overlap(i, j, polys)) {
                    uf.uni(i, j);
                }
            }
        }

        cout << uf.forests << endl;
    }

    return 0;
}
