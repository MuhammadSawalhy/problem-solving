// ----------------------------------------------------------------------------
// Problem : C. Longest Regular Bracket Sequence
// Author  : Muahmmad Assawalhy
// Date    : 06-09-22
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
  string s;
  cin >> s;
  vi ind;
  int mx = 0;
  int cnt = 1;
  vector<int> length(s.size());
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      ind.push_back(i);
    } else if (!ind.empty()) {
      int j = ind.back();
      ind.pop_back();
      int l = i + 1 - j;
      if (j > 0 && s[j - 1] == ')')
        l += length[j - 1];
      length[i] = l;
      if (l > mx) {
        mx = l;
        cnt = 1;
      } else if (mx == l)
        cnt++;
    }
  }

  debug(length);

  cout << mx << " " << cnt << endl;
  return 0;
}
