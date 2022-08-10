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

vector<pair<int, int>> get_prime_factors(int n) {
  vector<pair<int, int>> result;
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

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  while (true) {
    cin >> n;
    if (!n)
      break;
    auto primes = get_prime_factors(n);
    int i = 1;
    for (auto &p : primes)
      i *= p.second + 1;
    if (i % 2)
      std::cout << "yes" << std::endl;
    else
      std::cout << "no" << std::endl;
  }
  return 0;
}
