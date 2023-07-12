// Date: 13-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

const double PI = acos(-1.0);
const double EPS = 1e-20;

typedef complex<double> point;

// clang-format off
#define X                       real()
#define Y                       imag()
#define ang(v)                  (atan2((v).Y, (v).X))
#define length(v)               (hypot((v).Y, (v).X))
#define normalize(v)            ((v) / length(v))
#define same_vec(p1,p2)         (dp(vec(p1,p2),vec(p1,p2)) < EPS)
#define vec(a,b)                ((b)-(a))
#define dp(a,b)                 ((conj(a)*(b)).real())    // a*b cos(T), if zero -> prep
#define cp(a,b)                 ((conj(a)*(b)).imag())    // a*b sin(T), if zero -> parllel
#define rotate(p,ang)           ((p)*exp(point(0,ang)))
#define rotate_about(p,a,ang)   (rotate(vec(a,p),ang)+a)
#define reflect_about(v,a,b)    (conj(vec(a,v)/vec(a,b))*vec(a,b)+a)
bool eq(double f, double s) { return abs(f - s) < EPS; }
// clang-format on

bool intersect_segments(point a, point b, point c, point d,
                        point &intersection) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false; // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersection = a + (b - a) * t1;

  // if (t1 < -EPS || t2 < -EPS || t2 > 1 + EPS)
  //   return false; // e.g. ab is ray, cd is segment ... change to whatever
  return true;
}

point nearest_to_segment(point a, point b, point c) {
  if (dp(a - b, c - b) < 0) {
    return b;
  }

  if (dp(b - a, c - a) < 0) {
    return a;
  }

  // the intersection lies in ab segment

  point d = c + rotate(point(1, 0), ang(b - a) + PI / 2);
  point res;
  intersect_segments(a, b, c, d, res);
  return res;
}

int n;
double x, y;
void solve() {
  vector<point> p;
  point m(x, y);
  for (int i = 0; i < n + 1; i++) {
    cin >> x >> y;
    p.push_back(point(x, y));
  }

  if (n == 0) {
    cout << p[0].real() << endl;
    cout << p[0].imag() << endl;
    return;
  }

  point inter;
  double d = 1e10;
  point ans;

  for (int i = 0; i < n; i++) {
    inter = nearest_to_segment(p[i], p[i + 1], m);
    if (length(m - inter) < d) {
      ans = inter;
      d = length(m - inter);
    }
  }

  cout << ans.real() << endl;
  cout << ans.imag() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(4);

  while (cin >> x) {
    cin >> y >> n;
    solve();
  }

  return 0;
}
