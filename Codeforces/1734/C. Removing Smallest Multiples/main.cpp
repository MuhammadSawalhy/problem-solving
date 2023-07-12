// Date: 23-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

#define ull unsigned long long

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    string s;
    cin >> n;
    cin >> s;
    vector<bool> e(n + 1);

    for (int i = 0; i < n; i++) {
      if (s[i] == '1')
        e[i + 1] = true;
    }

    debug(s);
    vector<int> num(n + 1, -1);
    long long ans = 0;
    for (int k = 1; k <= n; k++) {
      int i = 1;

      if (!e[k]) {
        for (int j = k; j <= n; j += k) {
          if (e[j])
            break;
          if (num[j] == -1)
            num[j] = k;
        }
        ans += num[k];
      }
    }

    cout << ans << endl;
  }
  return 0;
}

// debug(s);
// vector<int> factors(1000);
// long long ans = 0;
// for (int k = 1; k <= n; k++) {
//   int i = 1;
//   factors[0] = 1;
//   auto primes = get_prime_factors(k);
//   for (auto [pr, a] : primes) {
//     while (a--) {
//       int ii = i;
//       for (int j = 0; j < ii; j++) {
//         factors[i++] = factors[j] * pr;
//       }
//     }
//   }
//
//   if (e[k]) {
//     for (int j = 0; j < i - 1; j++) {
//       v[factors[j]] = false;
//     }
//   } else {
//     for (int j = 0; j < i; j++) {
//       if (v[factors[j]]) {
//         debug(factors[j]);
//         ans += factors[j];
//         break;
//       }
//     }
//     for (int j = 0; j < i - 1; j++) {
//       v[factors[j]] = false;
//     }
//   }
