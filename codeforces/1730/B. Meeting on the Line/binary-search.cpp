// Date: 26-09-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void solve() {
  int n;
  cin >> n;
  vector<int> x(n);
  vector<int> t(n);

  for (auto &i : x)
    cin >> i;
  for (auto &i : t)
    cin >> i;

  auto get_intersection = [&](int T) {
    int mnl = INT_MAX, mxr = INT_MIN;
    for (int i = 0; i < n; i++) {
      mnl = min(mnl, x[i] - (T - t[i]));
      mxr = max(mxr, x[i] + (T - t[i]));
    }

    return make_pair(mnl, mxr);
  };

  int s = 0, e = 1e9;
  while (s < e) {
    int mid = (s + e) >> 1;
    auto inter = get_intersection(mid);
    if (inter.first <= inter.second) {
      e = mid;
    } else {
      s = mid + 1;
    }
  }


  auto inter = get_intersection(s);
  debug(s, inter);
  cout << setprecision(14) << (inter.first + inter.second) / 2.0 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
