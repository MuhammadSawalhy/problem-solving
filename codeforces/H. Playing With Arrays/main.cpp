// Date: 27-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

vector<int> solve(int n, int start = 0) {
  if (n == 2) {
    return {start + 1, start + 2};
  }

  if (n == 1) {
    return {start + 1};
  }

  auto vec = solve(n / 2, start + (n + 1) / 2);
  if (n & 1) {
    vec.insert(vec.begin(), vec.back());
    vec.pop_back();
  }

  vector<int> ans;
  int j = 0;
  for (int i = 1; i <= (n + 1) / 2; i++) {
    ans.push_back(start + i);
    if (j < (int)vec.size()) {
      ans.push_back(vec[j++]);
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    auto vec = solve(n);
    for (int i = 0; i < n; i++)
      cout << vec[i] << " \n"[i == n - 1];
  }

  return 0;
}
