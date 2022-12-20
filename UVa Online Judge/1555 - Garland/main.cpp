// Date: 30-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

int n;
double a;

void solve() {
  double s = 0, e = 1e10;

  auto calc = [&](int i, double x) {
    return 1.0 * (2 - i) * a + (i - 1) * x + (i - 2) * (i - 1);
  };

  auto valid = [&](double b) {
    double previous = a;
    double x = (b - a * (2 - n) - (n - 2) * (n - 1)) / (n - 1);// I should binary search it

    if (x >= a) return true;
    debug(x, b);

    double m = a;
    int i = (a - x + 3) / 2;

    if (i >= n + 1) return true;
    if (i <= -1) return false;

    debug(i, calc(i, x));

    if (i >= 1 || i <= n)
      m = min(m, calc(i, x));

    if (i + 1 <= n) {
      m = min(m, calc(i + 1, x));
    }

    if (i - 1 >= 1) {
      m = min(m, calc(i - 1, x));
    }

    return m != a && m >= 0;
  };

  while (e - s > 1e-5) {
    double mid = (s + e) / 2;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid;
    }
  }

  cout << e << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cout << fixed << setprecision(2);

  while (cin >> n >> a)
    solve();

  return 0;
}
