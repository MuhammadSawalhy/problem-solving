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

void solve() {
  while (true) {
    ull n, m, ans = 1;
    cin >> n >> m;
    if (n == 0)
      break;

    map<int, int> m_primes;

    for (ull i = m; i > 1; i--) {
      auto p = get_prime_factors(i);
      for (auto pp : p) {
        m_primes[pp.first] += pp.second;
      }
    }

    debug(m_primes);

    for (ull i = n; i > n - m; i--) {
      int k = i;

      for (auto &p : m_primes) {
        while (k % p.first == 0 && p.second > 0) {
          k /= p.first;
          p.second--;
        }
      }

      ans *= k;
    }

    debug(m_primes);
    debug(ans);

    std::cerr << "----------" << std::endl;

    for (auto &p : m_primes) {
      while (p.second > 0) {
        ans /= p.first;
        p.second--;
      }
    }

    std::cout << n << " things taken " << m << " at a time is " << ans
              << " exactly." << std::endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
