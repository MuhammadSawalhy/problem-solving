// Date: 07-10-22
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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<int, int> fr;
  for (int i = 0; i < n; i++) {
    fr[s[i]]++;
  }

  string t;

  int c = n / k;
  while (k--) {
    char tt = 'z';
    int cnt = 0;
    for (char ch = 'a'; ch <= 'y'; ch++) {
      if (fr[ch] && cnt < c) {
        fr[ch]--;
        cnt++;
      } else if (tt == 'z') {
        tt = ch;
      }

      if (cnt == c && tt != 'z')
        break;
    }

    t += tt;
  };

  cout << t << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
