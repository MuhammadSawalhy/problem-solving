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

map<ull, ull> get_prime_factors(ull n) {
  map<ull, ull> result;
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

void solve() {
  ull n;
  cin >> n;
  auto primes = get_prime_factors(n);

  int s = 0;
  for (auto p : primes) {
    s += p.second;
  }

  if (s < 2) {
    cout << 1 << endl;
    cout << 0 << endl;
    return;
  }

  if (s == 2) {
    cout << 2 << endl;
    return;
  }

  debug(primes);

  ull d = 1;
  int i = 0;
  for (auto p : primes) {
    if (i == 2)
      break;
    while (p.second--) {
      if (i == 2)
        break;
      d *= p.first;
      i++;
    }
  }

  cout << 1 << endl;
  cout << d << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
