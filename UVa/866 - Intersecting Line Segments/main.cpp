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

bool intersect_segments(point a, point b, point c, point d, point &intersect) {
  double d1 = cp(a - b, d - c), d2 = cp(a - c, d - c), d3 = cp(a - b, a - c);
  if (fabs(d1) < EPS)
    return false; // Parllel || identical

  double t1 = d2 / d1, t2 = d3 / d1;
  intersect = a + (b - a) * t1;

  if (t1 < -EPS || t1 > 1 + EPS || t2 < -EPS || t2 > 1 + EPS)
    return false; // e.g. ab is ray, cd is segment ... change to whatever
  return true;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<point, point>> lines;
  vector<vector<point>> intersections(n);

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    point a(x, y);
    cin >> x >> y;
    point b(x, y);
    lines.push_back({a, b});
  }

  point inter;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (intersect_segments(lines[i].first, lines[i].second, lines[j].first,
                             lines[j].second, inter)) {
        bool ok = true;
        for (auto &intr : intersections[i]) {
          if (same_vec(intr, inter)) {
            ok = false;
            break;
          }
        }
        if (ok)
          intersections[i].push_back(inter);

        ok = true;
        for (auto &intr : intersections[j]) {
          if (same_vec(intr, inter)) {
            ok = false;
            break;
          }
        }
        if (ok)
          intersections[j].push_back(inter);
      }
    }
  }

  debug(intersections);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += intersections[i].size() + 1;
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    solve();
    if (t)
      cout << endl;
  }

  return 0;
}
