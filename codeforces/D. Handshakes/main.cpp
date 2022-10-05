// Date: 30-09-22
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

  vector<int> ans;
  vector<vector<int>> students(n);
  for (int i = 0; i < n; i++) {
    int s;
    cin >> s;
    students[s].push_back(i);
  }

  int c = 0;
  // 0, 1, 2, 3 - 3m, 4 - 3m, ...
  while (ans.size() < n) {
    while (students[c].empty() && c >= 3) {
      // greedly choose the bigget availbe option
      c -= 3;
    }

    if (students[c].empty()) {
      cout << "Impossible" << endl;
      return;
    }

    ans.push_back(students[c].back());
    students[c].pop_back();
    c++;
  }

  cout << "Possible" << endl;
  for (auto i : ans)
    cout << i + 1 << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
