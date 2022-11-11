// Date: 19-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#ifndef ONLINE_JUDGE
#include "debug.hpp"
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

struct segment {
  point start;
  point end;
};

vector<int> memo(2e5, -1);

int fall(int k, point p, vector<segment> &segments) {
  if (~k && ~memo[k]) {
    return memo[k];
  }

  int value;
  point inter;
  int target = -1;

  segment vert;
  vert.start = p;
  vert.end = point(p.X, 0);
  for (int i = 0; i < (int)segments.size(); i++) {
    if (i == k)
      continue;
    if (intersect_segments(segments[i].start, segments[i].end, vert.start,
                           vert.end, inter)) {
      target = i;
      break;
    }
  }

  debug(k, p, target);

  if (~target) {
    value = fall(target, segments[target].end, segments);
  } else {
    value = p.X;
  }

  if (~k)
    memo[k] = value;

  return value;
}

void solve() {
  memo.assign(2e5, -1);

  int n;
  cin >> n;
  vector<segment> segs(n);

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    segs[i].start = point(x, y);
    cin >> x >> y;
    segs[i].end = point(x, y);
    if (segs[i].end.Y > segs[i].start.Y)
      swap(segs[i].start, segs[i].end);
  }

  sort(segs.begin(), segs.end(),
       [](segment l, segment r) { return l.end.Y > r.end.Y; });

  cin >> n;
  while (n--) {
    cin >> x >> y;
    cout << fall(-1, point(x, y), segs) << endl;
  }
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
