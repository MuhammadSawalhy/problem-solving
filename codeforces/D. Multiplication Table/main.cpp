// Date: 26-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  long long n, m, k;
  cin >> n >> m >> k;
  long long s = 0, e = 1e12;

  auto valid = [&](long long val) {
    long long cnt = 0;
    for (long long i = 1; i <= n; i++) {
      cnt += min(val, m * i) / i;
    }
    return cnt >= k;
  };

  while (e - s > 1) {
    long long mid = (s + e) >> 1;
    if (valid(mid)) {
      e = mid;
    } else {
      s = mid;
    }
  }

  cout << e << endl;

  return 0;
}
