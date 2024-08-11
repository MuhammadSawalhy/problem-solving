// Date: 22-09-22
#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n;
  int c = 0;
  while (cin >> n) {
    vector<int> h(n);
    for (auto &i : h)
      cin >> i;
    vector<int> v;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      while (!v.empty() && h[i] < v.back()) {
        v.pop_back();
        ans++;
      }

      if (!v.empty() && v.back() == h[i])
        continue;
      v.push_back(h[i]);
    }

    while (!v.empty() && 0 < v.back()) {
      v.pop_back();
      ans++;
    }

    cout << "Case " << ++c << ": " << ans << endl;
  }
  return 0;
}
