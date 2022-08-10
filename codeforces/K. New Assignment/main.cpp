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

int t_case;

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
  int n;
  cin >> n;
  vi p(n);
  vi f;

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }

  char g;
  for (int i = 0; i < n; i++) {
    cin >> g;

    if (g == 'M') {
      auto primes = get_prime_factors(p[i]);
      for (auto p : primes) {
        m[p.first].push_back(i);
      }
    }

    else
      f.push_back(p[i]);
  }

  int ans = n;

  for (const int &pf : f) {
    auto primes = get_prime_factors(pf);
    for (auto p : primes) {
      for (auto mp : m) {
        if (p.first == mp.first) {
          for (auto i : mp.second) {
            if (me[i]) {
              me[i] = false;
              ans--;
              break;
            }
          }
        }
      }
    }
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
