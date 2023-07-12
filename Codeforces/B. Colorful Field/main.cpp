// Date: 11-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n, m, k, t;
  cin >> n >> m >> k >> t;

  vector<int> wasted;
  while (k--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    wasted.push_back(i * m + j);
  }

  sort(wasted.begin(), wasted.end());

  while (t--) {
    int i, j;
    cin >> i >> j;
    i--, j--;
    int k =
        lower_bound(wasted.begin(), wasted.end(), i * m + j) - wasted.begin();
    if (k < wasted.size() && wasted[k] == i * m + j) {
      cout << "Waste" << endl;
    } else {
      const vector<string> fruits = {"Carrots", "Kiwis", "Grapes"};
      cout << fruits[(i * m + j - k) % 3] << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
}
