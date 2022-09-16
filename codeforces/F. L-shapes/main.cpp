//============================================================================
// Problem     : F. L-shapes
// Author      : Muahmmad Assawalhy
// Date        : 31-08-22
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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> mat;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    mat.push_back(row);
  }

  const vector<pair<int, int>> L = {
      {0, 0},
      {1, 1},
      {1, 0},
      {0, 1},
  };

  if (n == 1 || m == 1) {
    cout << "NO" << endl;
    return;
  }

  auto isvalid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  auto getl = [&](int i, int j) -> pair<int, int> {
    for (auto l : L) {
      if (mat[i + l.first][j + l.second] == '.') {
        for (auto ll : L) {
          if (ll == l)
            continue;
          if (mat[i + ll.first][j + ll.second] != '*')
            goto l_loop;
        }
        return l;
      }
    l_loop:;
    }

    return {-1, -1};
  };

  const vector<pair<int, int>> around = {
    {-1, -1},
    {0, -1},
    {1, -1},
    {2, -1},
    {2, 0},
    {2, 1},
    {2, 2},
    {1, 2},
    {0, 2},
    {-1, 2},
    {-1, 1},
    {-1, 0},
  };

  auto isvalid_l = [&](int i, int j) -> bool {
    auto l = getl(i, j);
    if (l.first == -1) return false;
    pair<int, int> skip = {l.first ? 2 * l.first : -1, l.second ? 2 * l.second : -1};
    for (auto a : around) {
      if (a == skip) continue;
      int x = i + a.first, y = j + a.second;
      if (!isvalid(x, y)) continue;
      if (mat[x][y] == '*') return false;
    }

    return true;
  };

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      if (isvalid_l(i, j)) {
        for (auto l : L) {
          if (mat[i + l.first][j + l.second] == '.') {
            for (auto ll : L) {
              if (ll == l)
                continue;
              mat[i + ll.first][j + ll.second] = 'x';
            }
          }
        }
      }
    }
  }

  debug(mat);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '*') {
        cout << "NO" << endl;
        return;
      }
    }
  }

  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
