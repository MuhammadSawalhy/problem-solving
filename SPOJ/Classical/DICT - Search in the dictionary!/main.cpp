// Date: 25-09-22
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
  string s;
  cin >> n;
  set<string> ds;
  while (n--) {
    cin >> s;
    ds.insert(s);
  }
  vector<string> d(ds.begin(), ds.end());
  cin >> n;
  int t;
  while (n--) {
    cin >> s;
    int i = lower_bound(d.begin(), d.end(), s + "a") - d.begin();
    int j = upper_bound(d.begin(), d.end(), s + "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz") - d.begin();
    cout << "Case #" << ++t << ":" << endl;
    if (i == j) {
      cout << "No match." << endl;
    } else {
      for (; i < j; i++) {
        cout << d[i] << endl;
      }
    }
  }
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
