// Date: 12-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

map<int, int>
get_prime_factors(int n) {
  map<int, int> result;
  int r = 0;

  while (n % 2 == 0) {
    r++;
    n = n / 2;
  }

  if (r > 0)
    result[2] = r;

  int sqn = sqrt(n);
  for (int i = 3; i <= sqn; i += 2) {
    r = 0;
    while (n % i == 0) {
      r++;
      n = n / i;
    }
    if (r > 0)
      result[i] = r;
  }

  if (n > 2)
    result[n] = 1;

  return result;
}

long long mod_inv(long long a, long long b) {
  return 1 < a ? b - mod_inv(b % a, a) * b / a : 1;
}

long long n, e, c;

void solve() {
  auto primes = get_prime_factors(n);
  long long phi = 1;

  for (auto [p, r] : primes) {
    phi *= p - 1;
  }

  long long d = mod_inv(e, phi);

  long long m = 1;
  while (d) {
    if (d & 1) {
      m *= c;
      m %= n;
    }
    c *= c;
    c %= n;
    d >>= 1;
  }

  cout << m << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  while (cin >> n >> e >> c)
    solve();

  return 0;
}
