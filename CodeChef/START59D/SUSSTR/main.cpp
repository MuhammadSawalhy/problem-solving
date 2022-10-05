// Date: 05-10-22
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
  string S, t;
  cin >> n >> S;
  deque<char> s(S.begin(), S.end());

  int alice = 1;
  while (!s.empty()) {
    char c;
    if (alice) {
      c = s.front();
      s.pop_front();
      if (c == '0')
        t = c + t;
      else
        t += c;
    } else {
      c = s.back();
      s.pop_back();
      if (c == '0')
        t += c;
      else
        t = c + t;
    }

    alice ^= 1;
  }

  cout << t << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
