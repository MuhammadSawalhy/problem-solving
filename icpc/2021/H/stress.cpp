// Date: 10-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  vector<string> v;
  while (n--) {
    string s;
    cin >> s;
    v.push_back(s);
  }

  do {
    int o = 0;
    for (auto s : v) {
      for (auto c : s) {
        if (c == '(') {
          o++;
        } else {
          if (!o) {
            goto line;
          }
          o--;
        }
      }
    }

    if (o == 0)
        return 0;
    line: ;
  } while (next_permutation(all(v)));

  cout << "impossible" << endl;

  return 0;
}
