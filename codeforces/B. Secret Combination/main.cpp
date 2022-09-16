// ----------------------------------------------------------------------------
// Problem : B. Secret Combination
// Author  : Muahmmad Assawalhy
// Date    : 07-09-22
// ----------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  string s;
  cin >> s;
  s += " "; // for easy shifting

  vector<string> str;

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < n; j++) {
      s[j] = '0' + ((s[j] - '0' + 1) % 10);
    }

    for (int k = 0; k < n; k++) { // n shifts
      for (int j = n; j > 0; j--) {
        s[j] = s[j - 1];
      }
      s[0] = s[n];
      s[n] = ' ';
      str.push_back(s);
    }
  }

  sort(all(str));
  cout << str[0] << endl;
  return 0;
}
