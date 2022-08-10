#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_arr(...)
#define debug_bits(...)
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

void solve() {
  int x, y, w, z;
  cin >> x >> y >> w >> z;

  map<pair<int, int>, bool> board;

  int n;
  cin >> n;
  while (n--) {
    int r, a, b;
    cin >> r >> a >> b;
    for (int i = a; i <= b; i++)
      board[{r, i}] = true;
  }

  int ans = -1;

  queue<pair<pair<int, int>, int>> qu;
  qu.push({{x, y}, 0});

  while (!qu.empty()) {
    auto [p, level] = qu.front();
    qu.pop();

    if (!board[p])
      continue;
    board[p] = false; // mark as visited

    debug(p, level);
    if (p.first == w && p.second == z) {
      ans = level;
      break;
    }

    qu.push({{p.first, p.second + 1}, level + 1});
    qu.push({{p.first, p.second - 1}, level + 1});

    qu.push({{p.first + 1, p.second}, level + 1});
    qu.push({{p.first + 1, p.second + 1}, level + 1});
    qu.push({{p.first + 1, p.second - 1}, level + 1});

    qu.push({{p.first - 1, p.second}, level + 1});
    qu.push({{p.first - 1, p.second + 1}, level + 1});
    qu.push({{p.first - 1, p.second - 1}, level + 1});
  }

  std::cout << ans << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
