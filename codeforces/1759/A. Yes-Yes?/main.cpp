// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

string validator;

void solve() {
  string s;
  cin >> s;

  if (validator.find(s) != string::npos) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  for (int i = 0; i < 100; i++) {
    validator += "Yes";
  }

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
