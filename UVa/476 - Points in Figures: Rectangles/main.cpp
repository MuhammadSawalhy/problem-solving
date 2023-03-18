#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define int ll
#define f(i, b) for (ll i = 0; i < b; i++)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

typedef vector<int> vi;
typedef vector<bool> vb;

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

typedef pair<double, double> point;

void solve() {
  string in;

  vector<pair<point, point>> rects;
  vector<point> points;

  while (true) {
    getline(cin, in);
    if (in == "*")
      break;
    istringstream istream(in);
    istream >> in;

    pair<point, point> rect;
    istream >> rect.first.first;
    istream >> rect.first.second;
    istream >> rect.second.first;
    istream >> rect.second.second;
    rects.push_back(rect);
  }

  debug(rects);

  while (true) {
    point p;
    cin >> p.first >> p.second;
    if (p.first == 9999.9 && p.second == 9999.9)
      break;
    points.push_back(p);
  }

  debug(points);

  int pi = 0, ri = 0;
  for (auto p : points) {
    pi++;
    ri = 0;
    bool contained = false;
    for (auto r : rects) {
      ri++;
      if (p.first > r.first.first && p.first < r.second.first &&
          p.second < r.first.second && p.second > r.second.second) {
        std::cout << "Point " << pi << " is contained in figure " << ri
                  << std::endl;
        contained = true;
      }
    }

    if (!contained) {
      std::cout << "Point " << pi << " is not contained in any figure"
                << std::endl;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
