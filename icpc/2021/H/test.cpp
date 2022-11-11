// Date: 10-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  // read test case

  int n;
  cin >> n;
  vector<string> parts;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    parts.push_back(s);
  }

  // read my solution output

  string res;
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    j--;
    res += parts[j];
  }

  int o = 0;
  for (auto c: res) {
    if (c == '(') {
      o++;
    } else {
      if (!o) {
        cout << res << endl;
        exit(1);
      }
      o--;
    }
  }

  return 0;
}
