// Date: 01-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void bs() {
  int n, k;
  cin >> n >> k;
  int x[n];
  for (int i = 0; i < n; i++)
    cin >> x[i];

  auto valid = [&](int m) {
    int cnt = 1;
    int last = x[0];

    for (int i = 1; i < n; i++) {
      if (x[i] - last >= m) {
        cnt++;
        last = x[i];
      }
    }

    return cnt >= k;
  };

  int s = 0, e = 1e9;

  while (s < e) {
    int mid = (s + e + 1) >> 1;
    if (valid(mid)) {
      s = mid;
    } else {
      e = mid - 1;
    }
  }

  cout << s << endl;
}

void greedy() {
#warning NOT COMPLETEED
  int n, k;
  cin >> n >> k;
  int x[n];
  for (int i = 0; i < n; i++)
    cin >> x[i];

  priority_queue<array<int, 3>> qu;
  for (int i = 1; i < n; i++) {
    qu.push({-(x[i] - x[i - 1]), i, i - 1}); // minus to sort ascending
  }

  int cnt = n;
  while (cnt > k) {
    auto t = qu.top();
    qu.pop();
    cnt--;
    if (t[2] == 0) {
    }
  }

  cout << -qu.top()[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    // bs();
    greedy();
  }
  return 0;
}
