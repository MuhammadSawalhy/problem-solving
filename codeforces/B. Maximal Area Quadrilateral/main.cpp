//============================================================================
// Problem     : B. Maximal Area Quadrilateral
// Author      : Muahmmad Assawalhy
// Date        : 02-09-22
//============================================================================

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

const double PI = acos(-1.0);
const double EPS = 1e-9;

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
// clang-format on

double angle(const point &p) {
  double a = ang(p);
  if (a < 0)
    a += 2 * PI;
  return a;
}

void solve() {
  int n;
  cin >> n;
  vector<point> p;

  point o(INT_MAX, INT_MAX);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (y < o.Y)
      o = point(x, y);
    p.push_back(point(x, y));
  }

  vector<pair<double, point>> angs;
  for (int i = 0; i < n; i++) {
    if (p[i] == o)
      continue;
    angs.push_back({angle(vec(o, p[i])), p[i]});
  }

  sort(all(angs), [](auto &l, auto &r) { return l.first < r.first; });

  debug(angs);

  vector<point> hull;
  hull.push_back(o);
  hull.push_back(angs[0].second);
  hull.push_back(angs[1].second);
  for (int i = 2; i < sz(angs); i++) {
    debug(hull);
    while (sz(hull) > 4 && angle(angs[i].second - hull[sz(hull) - 1]) <=
           angle(hull[sz(hull) - 1] - hull[sz(hull) - 2])) {
      debug(angle(angs[i].second - hull[sz(hull) - 1]),
           angle(hull[sz(hull) - 1] - hull[sz(hull) - 2]));
      hull.pop_back();
    }

    hull.push_back(angs[i].second);
  }

  auto area = [&](int i, int j, int k, int a) {
    return 0.5 * (cp(hull[j] - hull[i], hull[k] - hull[j]) +
                  cp(hull[a] - hull[k], hull[i] - hull[a]));
  };

  double ans = 0;
  for (int i = 0; i < sz(hull); i++) {
    for (int j = i + 1; j < sz(hull); j++) {
      for (int k = j + 1; k < sz(hull); k++) {
        for (int a = k + 1; a < sz(hull); a++) {
          ans = max(ans, area(i, j, k, a));
          ans = max(ans, area(i, k, j, a));
        }
      }
    }
  }

  cout << fixed << setprecision(6) << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
