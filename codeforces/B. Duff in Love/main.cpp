#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...) 0
#endif

template <typename T> inline bool ckmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <typename T> inline bool ckmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <typename T> inline void clear(T *arr, int val, int n) { for (int i = 0; i < n; arr[i++] = val); }
// clang-format on

typedef long long ll;
typedef unsigned long long ull;

const int maxn = pow(2, 31) - 1;
ll s;

template <typename T>
vector<pair<T, int>> get_prime_factors(T n) {
  vector<pair<T, int>> result;
  int r = 0;

  while (n % 2 == 0) {
    r++;
    n = n / 2;
  }

  if (r > 0)
    result.push_back({2, r});

  int sqn = sqrt(n);
  for (int i = 3; i <= sqn; i += 2) {
    r = 0;
    while (n % i == 0) {
      r++;
      n = n / i;
    }
    if (r > 0)
      result.push_back({i, r});
  }

  if (n > 2)
    result.push_back({(int)n, 1});

  return result;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> s;

  auto primes = get_prime_factors(s);

  ull a = 1;

  debug(s, primes);
  for (auto v : primes) {
    a *= v.first;
  }

  std::cout << a << std::endl;

  return 0;
}
