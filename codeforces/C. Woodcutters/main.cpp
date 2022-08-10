#include <bits/stdc++.h>

using namespace std;

// clang-format off
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

int n;
vector<pair<int, int>> trees;
vector<array<int, 3>> mem;

enum status { left, right, stand };

int max_trees(int i, status prev) {
  if (i == n - 1)
    return 1;

  int &m = mem[i][prev];

  if (m != -1)
    return m;

  int space;

  // try left
  space = trees[i].first - trees[i - 1].first - 1;
  space -= trees[i].second;
  if (prev == status::right)
    space -= trees[i - 1].second;
  if (space >= 0)
    m = max(m, 1 + max_trees(i + 1, status::left));

  // try right
  space = trees[i + 1].first - trees[i].first - 1;
  space -= trees[i].second;
  if (space >= 0)
    m = max(m, 1 + max_trees(i + 1, status::right));

  // try stand
  m = max(m, max_trees(i + 1, status::stand));

  return m;
};

void solve() {
  cin >> n;
  trees.clear();
  trees.resize(n);
  mem = vector<array<int, 3>>(n, array<int, 3>({-1, -1, -1}));

  for (auto &i : trees) {
    cin >> i.first;
    cin >> i.second;
  }

  if (n == 1) {
    std::cout << 1 << std::endl;
    return;
  }

  int m = 1 + max_trees(1, status::left);

  debug(trees);
  debug(mem);

  std::cout << m << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
