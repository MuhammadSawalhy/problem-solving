// ----------------------------------------------------------------------------
// Problem : D. Pair Of Lines
// Author  : Muahmmad Assawalhy
// Date    : 16-09-22
// ----------------------------------------------------------------------------

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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

const double PI = acos(-1.0);
const double EPS = 1e-80;

typedef complex<ll> point;

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

vector<point> points;

bool collinear(int i, int j, int k) {
  return eq(cp(points[j] - points[i], points[k] - points[j]), 0);
}

ll get_slope(int i, int j) {
  double a = ang(points[i] - points[j]);
  if (a <= 0)
    a += PI;
  // get 9 numbers after the decimal point to make sure that slopes are unique
  return a * 1e9;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    ll x, y;
    cin >> x >> y;
    points.push_back(point(x, y));
  }

  if (n < 5) {
    cout << "YES" << endl;
    return 0;
  }

  // search for collinear three points
  auto getline = [&](int o) {
    vector<int> line;

    map<ll, int> slopes;
    for (int i = 0; i < n; i++) {
      if (i == o)
        continue;
      auto s = get_slope(o, i);

      if (slopes.find(s) != slopes.end()) {
        // we got the three points
        line = {o, i, slopes[s]};
        break;
      }

      slopes[s] = i;
    }

    return line;
  };

  bool used[n];
  memset(used, 0, sizeof used);

  vector<int> line;
  for (int i = 0; i < 3; i++) {
    line = getline(i);
    if (!line.empty())
      break;
  }

  if (line.empty()) {
    cout << "NO" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (collinear(line[0], line[1], i))
      used[i] = true;
  }

  debug(line);
  debug_itr(used, used + n);

  line.clear();
  for (int i = 0; i < n; i++) {
    if (!used[i])
      line.push_back(i);
    if (line.size() == 2)
      break;
  }

  if (line.size() < 2) {
    cout << "YES" << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    if (used[i])
      continue;
    if (collinear(line[0], line[1], i))
      used[i] = true;
  }

  debug(line);
  debug_itr(used, used + n);

  for (int i = 0; i < n; i++) {
    if (!used[i]) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}
