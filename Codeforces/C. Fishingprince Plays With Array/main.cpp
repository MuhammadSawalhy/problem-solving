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

#define f(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define int ll

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int t_case;
int n, m;

void expand(int j, vector<pair<int, int>> &v) {
  int k = 1;

  while (j % m == 0) {
    k *= m;
    j /= m;
  }

  if (v.size() > 0 && v.back().first == j)
    v.back().second += k;
  else
    v.push_back({j, k});
}

void solve() {
  cin >> n >> m;

  vector<pair<int, int>> a;

  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    expand(j, a);
  }

  int k;
  vector<pair<int, int>> b;
  cin >> k;
  for (int i = 0; i < k; i++) {
    int j;
    cin >> j;
    expand(j, b);
  }

  std::cerr << "------" << std::endl;
  debug(n, m);
  debug(a);
  debug(b);

  if (a.size() != b.size()) {
    std::cout << "No" << std::endl;
    return;
  }

  for (int i = 0; i < a.size(); i++) {
    if (a[i].first != b[i].first || a[i].second != b[i].second) {
      std::cout << "No" << std::endl;
      return;
    }
  }

  std::cout << "Yes" << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
