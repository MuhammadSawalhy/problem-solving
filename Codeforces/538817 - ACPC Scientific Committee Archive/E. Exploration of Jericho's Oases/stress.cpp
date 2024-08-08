#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define el '\n'
#define popcount __builtin_popcountll
#define ios                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define vi vector<int>
#define sz(x) (int) x.size()
#define rep(i, l, r) for (int i = l; i < r; i++)
const int mod = 1e9 + 7, INF = 1e9 + 10;
const ld PI = acos(-1), eps = 1e-7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

template<class T>
using ordered_set = tree<
        T,
        null_type,
        less<T>,
        rb_tree_tag,
        tree_order_statistics_node_update>;


const ld EPS = 1e-9;
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
    ld dist() const { return sqrt((ld) dist2()); }
    // angle to x-axis in interval [-pi, pi]
    ld angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); } // makes dist()=1
    P perp() const { return P(-y, x); }       // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(ld a) const {
        return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream &operator<<(ostream &os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

bool equal(ld a, ld b) {
    return abs(a - b) < EPS;
}

int main() {
    ios;
    int t;
    cin >> t;
    while (t--) {
        Point<ld> a, b, c, t;
        int f;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> t.x >> t.y >> f;
        Point<ld> ba = a - b, bc = c - b, bt = t - b;
        if (f) swap(ba, bc);
        ld val = bc.dot(bt);
        if (val <= 0 || equal(val, bc.dist() * bt.dist()) || sgn(bc.cross(ba)) != sgn(bc.cross(bt))) {
            cout << "NO" << el;
            continue;
        }
        cout << "YES" << el;
        ld bcbtAngle = asin(bc.cross(bt) / bc.dist() / bt.dist());
        bcbtAngle *= 2;
        Point bc2 = bc.rotate(bcbtAngle);
        ld ans = sgn(ba.cross(bc2)) * acos(ba.dot(bc2) / ba.dist() / bc2.dist()) * 180 / PI;
        cout << fixed << setprecision(9) << ans << el;
    }
}
