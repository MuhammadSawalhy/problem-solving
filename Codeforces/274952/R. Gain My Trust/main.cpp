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
  int t_cases = 1;
  cin >> t_cases;
  string s;
  int k;
  while (t_cases--) {
    cin >> s >> k;
    vector<string> passwords;
    for (int i = 0; i < 1 << (int)s.size(); i++) {
      string pass = "";
      for (int j = 0; j < (int)s.size(); j++) {
        if (i & (1 << j)) {
          pass += s[j];
        }
      }

      passwords.push_back(pass);
    }

    sort(passwords.begin(), passwords.end());
    cout << passwords[k - 1] << endl;
  }
  return 0;
}
