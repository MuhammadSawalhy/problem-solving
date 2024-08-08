#include <bits/stdc++.h>

using namespace std;

using ll = long long;
//#define int ll
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second
#define pb push_back

typedef long double ld;
#define double ld

template<class T>
int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a - *this).cross(b - *this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double) dist2()); }
    // angle to x-axis in interval [-pi, pi]
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); }       // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream &operator<<(ostream &os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<ll> P;
vector<P> convexHull(vector<P> pts) {
    if (sz(pts) <= 1) return pts;
    sort(all(pts));
    vector<P> h(sz(pts) + 1);
    int s = 0, t = 0;
    for (int it = 2; it--; s = --t, reverse(all(pts)))
        for (P p: pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) <= 0) t--;
            h[t++] = p;
        }
    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int n;
vector<P> v;
int id;

void recalc(double a, double b) {
    double cur = a * v[id].x + b * v[id].y;
    while (true) {
        int nid = (id + 1) % n;
        double ncur = a * v[nid].x + b * v[nid].y;
        if (ncur <= cur) break;
        id = nid;
        cur = ncur;
    }

    while (true) {
        int nid = (id + n - 1) % n;
        double ncur = a * v[nid].x + b * v[nid].y;
        if (ncur <= cur) break;
        id = nid;
        cur = ncur;
    }
}

pair<double, double> intersect(double a1, double b1, double c1, double a2, double b2, double c2) {
    c1 = -c1;
    c2 = -c2;

    double D = a1 * b2 - a2 * b1;
    double D1 = c1 * b2 - c2 * b1;
    double D2 = a1 * c2 - a2 * c1;
    return {D1 / D, D2 / D};
}

const double pi = acos(double(-1));

void solve() {
    double r, alpha;
    cin >> n >> r >> alpha;

    alpha *= pi / 180;

    v.resize(n);
    for (auto &p: v)
        cin >> p.x >> p.y;

    v = convexHull(v);
    n = v.size();
    id = 0;

    if (n == 1) {
        cout << r << "\n";
        return;
    }

    double ans = 1e18;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double A = v[i].x - v[j].x;
        double B = v[i].y - v[j].y;
        swap(A, B);
        B = -B;

        Point<double> p = Point<double>(A, B).rotate(alpha);
        recalc(p.x, p.y);

        auto q = intersect(A, B, -A * v[i].x - B * v[i].y, p.x, p.y, -p.x * v[id].x - p.y * v[id].y);
        ans = min(ans, sqrt(q.fi * q.fi + q.se * q.se));
    }

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double A = v[i].x - v[j].x;
        double B = v[i].y - v[j].y;
        swap(A, B);
        B = -B;

        Point<double> p = Point<double>(A, B).rotate(-alpha);
        recalc(p.x, p.y);

        auto q = intersect(A, B, -A * v[i].x - B * v[i].y, p.x, p.y, -p.x * v[id].x - p.y * v[id].y);
        ans = min(ans, sqrt(q.fi * q.fi + q.se * q.se));
    }

    cout << max(ans, r) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);

    int t;
    cin >> t;
    while (t--)
        solve();
}
