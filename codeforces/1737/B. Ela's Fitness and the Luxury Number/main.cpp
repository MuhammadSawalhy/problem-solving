// Date: 07-10-22
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#endif

long long count(long long a) {
  // luxurious between 0 and a
  if (a == 1)
    return 1;
  if (a < 1)
    return 0;
  long long ans = sqrt(a); // num of complete squares

  ans += (ans - 1LL) * 2LL;

  long long sq = sqrt(a);
  ans += a / sq - sq;

  return ans;
}

void solve() {
  long long l, r;
  cin >> l >> r;
  long long arr[2] = {l, r};
  cout << count(r) - count(l - 1) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
