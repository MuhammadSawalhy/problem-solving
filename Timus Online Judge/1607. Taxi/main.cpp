#include <bits/stdc++.h>

using namespace std;

void solve() {
  int p, pp, d, dd;
  cin >> p >> pp >> d >> dd;
  int x = 0, y = 0;
  int driver = false;

  while (x * pp + y * dd < d - p) {
    if (driver) {
      y++;
    } else {
      x++;
    }

    driver = !driver;
  }

  if (driver)
    std::cout << d - y * dd << std::endl;
  else
    std::cout << p + x * pp << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
