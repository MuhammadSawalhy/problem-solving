// Date: 11-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

constexpr int MAX_SIZE = 2;
struct trie {
  trie *child[MAX_SIZE];
  bool is_leaf = false;
  int count = 0;
  pair<int, int> xy;
  char value;

  trie() {
    for (int i = 0; i < MAX_SIZE; i++) {
      child[i] = nullptr;
    }
  }

  ~trie() {
    for (int i = 0; i < MAX_SIZE; i++) {
      if (child[i] == nullptr)
        continue;
      delete child[i];
    }
  }

  trie *insert(const char *str, pair<int, int> xy) {
    count++;
    if (*str == '\0') {
      is_leaf = true;
      this->xy = xy;
      return this;
    }

    assert(*str != '\0');
    int cur = *str - 'a';
    if (child[cur] == nullptr) {
      child[cur] = new trie();
      child[cur]->value = *str;
    }
    return child[cur]->insert(str + 1, xy);
  }
};

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

  trie t;

  auto valid = [&](int x, int y) {
    return x >= 0 && x < dx && y >= 0 && y < dy;
  };

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

      string st = grid[y][x] == '.' ? "a" : "b";

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

        if (valid(x, y)) {
          st += grid[y][x] == '.' ? "a" : "b";
        } else {
          st += "a";
        }

        if (valid(x, y) && grid[y][x] == 'X')
          cnt--;
      }

      debug(st.c_str(), (pair<int, int>){i, dy - 1 - j});
      t.insert(st.c_str(), {i, dy - 1 - j});
    }
  }

  double expected = 0;
  int m = -1;
  vector<pair<int, int>> mm;
  // debug(t.child[1]->child[0]->child[0]->child[0]->child[0]->child[0]->child[0]->xy);

  function<void(trie *, int)> dfs = [&](trie *tt, int depth = 0) {
    if (tt == nullptr)
      return;

    if (tt->is_leaf) {
      depth--;
      assert(tt->count == 1);
      expected += 1.0 * depth / dy / dx;
      if (depth > m) {
        m = depth;
        mm = {tt->xy};
      } else if (depth == m) {
        mm.push_back(tt->xy);
      }
      return;
    }

    dfs(tt->child[0], depth + (tt->count > 1));
    dfs(tt->child[1], depth + (tt->count > 1));
  };

  dfs(&t, 0);

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
