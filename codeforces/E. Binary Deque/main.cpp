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

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> a(n);

  int sum = 0;

  for (int &i : a) {
    cin >> i;
    if (i)
      sum++;
  }

  if (sum == s) {
    std::cout << 0 << std::endl;
    return;
  }

  if (sum < s) {
    std::cout << -1 << std::endl;
    return;
  }

  vector<ull> pos;

  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i - 1]) {
      pos.push_back(i - last);
      last = i;
    }
  }

  reverse(all(pos));

  last = n;
  for (int i = n - 1; i >= 0; i--) {
    if (a[i]) {
      pos.push_back(last - i);
      last = i;
    }
  }

  std::cerr << "----------" << std::endl;
  debug(sum, s, pos);

  for (ull i = 1; i < pos.size(); i++) {
    pos[i] += pos[i - 1];
  }

  ull ans = ULLONG_MAX;

  for (ull i = pos.size() / 2 - 1; i <= pos.size() / 2 - 1 + sum - s; i++) {
    ans = min(ans, pos[i] - pos[i - (sum - s)]);
  }

  std::cout << ans << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
