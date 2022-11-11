// Date: 11-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int dx, dy;
  cin >> dx >> dy;
  vector<string> grid;
  int markers = 0;

  for (int i = 0; i < dy; i++) {
    string s;
    cin >> s;
    grid.push_back(s);
    for (auto c: s)
      markers += c == 'X';
  }

  auto valid = [&](int x, int y) {
    return x >= 0 && x < dx && y >= 0 && y < dy;
  };

  vector<pair<vector<int>, pair<int, int>>> poss;

  for (int j = dy - 1; j >= 0; j--) {
    for (int i = 0; i < dx; i++) {
      int cnt = markers;
      int steps = 0;
      int x = i, y = j;

      if (grid[y][x] == 'X') {
        cnt--;
      }

      enum Dir { up,
                 right,
                 down,
                 left };
      Dir dir = up;
      int flips = 0;
      int cs = 1;
      int s = 1;
      vector<int> p;

      while (cnt) {
        if (s == 0) {
          dir = Dir(((int) dir + 1) % 4);
          s = cs;
          flips++;
          if (flips & 1) {
            cs++;
          }
        }

        if (dir == up) {
          y--;
        } else if (dir == right) {
          x++;
        } else if (dir == down) {
          y++;
        } else if (dir == left) {
          x--;
        }

        s--;
        steps++;

        if (valid(x, y) && grid[y][x] == 'X') {
          p.push_back(steps);
          cnt--;
        }
      }

      poss.push_back({p, {i, dy - 1 - j}});
    }
  }

  double expected = 0;
  int m = -1;
  vector<pair<int, int>> mm;

  sort(all(poss));

  for (int i = 0; i < dy * dx; i++) {
    auto &[v, ind] = poss[i];
  }

  sort(all(mm), [](auto l, auto r) { return l.second == r.second ? l.first < r.first : l.second < r.second; });

  cout << setprecision(3) << fixed << expected << endl;
  cout << m << endl;
  for (int k = 0; k < mm.size(); k++) {
    auto [i, j] = mm[k];
    cout << "(" << i + 1 << "," << j + 1 << ")"
         << " \n"[k == mm.size() - 1];
  }

  return 0;
}
