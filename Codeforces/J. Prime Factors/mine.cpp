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

vector<pair<ull, ull>> get_prime_factors(ull n) {
  vector<pair<ull, ull>> result;
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
    result.push_back({n, 1});

  return result;
}

void solve() {
  int n;
  cin >> n;
  auto primes = get_prime_factors(n);

  for (int i = 0; i < sz(primes) - 1; i++) {
    cout << "(" << primes[i].first << "^" << primes[i].second << ")*";
  }

  cout << "(" << primes.back().first << "^" << primes.back().second << ")"
       << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
