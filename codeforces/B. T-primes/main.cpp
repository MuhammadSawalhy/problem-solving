// Date: 03-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

bool is_prime(long long n) {
  if (n < 2)
    return false;
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for (long long i = 3; i * i <= n; i += 2)
    if (n % i == 0)
      return false;
  return true;
}

void solve() {
  int n;
  cin >> n;
  while (n--) {
    long long x;
    cin >> x;
    debug((int)sqrt(x));
    if (x == (long long)sqrt(x) * sqrt(x) && is_prime(sqrt(x))) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
    solve();
  return 0;
}
