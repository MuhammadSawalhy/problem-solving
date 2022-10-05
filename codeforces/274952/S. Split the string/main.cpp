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

bool make_palin(string &s) {
  char odd = 0;
  string ss;
  sort(s.rbegin(), s.rend());
  while (!s.empty()) {
    char c1 = s.back();
    s.pop_back();
    if (s.empty()) {
      if (odd != 0)
        return false;
      odd = c1;
      break;
    }
    char c2 = s.back();
    s.pop_back();
    if (c1 == c2) {
      ss += c1;
    } else {
      if (odd != 0)
        return false;
      odd = c1;
      s.push_back(c2);
    }
  }
  s = ss;
  if (odd != 0)
    s += odd;
  reverse(ss.begin(), ss.end());
  s += ss;
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  string s;
  for (int t = 1; t <= t_cases; t++) {
    cin >> s;
    string a, b;
    bool odd_taken = false;
    vector<pair<string, string>> palins;
    sort(s.rbegin(), s.rend());
    b = s;
    debug(s);
    while (!s.empty()) {
      char c1 = s.back();
      s.pop_back();
      b.pop_back();
      if (s.empty()) {
        if (!odd_taken) {
          a += c1;
          odd_taken = true;
        } else {
          b = c1 + b;
        }
        assert(make_palin(a)); // it is guaranteed that this is a palin
        palins.push_back({a, b});
        break;
      }
      char c2 = s.back();
      s.pop_back();
      b.pop_back();
      if (c1 == c2) {
        a += c1;
        if (!odd_taken) {
          assert(make_palin(a)); // it is guaranteed that this is a palin
          palins.push_back({a, b + c2});
        }
        a += c2;
      } else if (!odd_taken) {
        a += c1;
        b = c2 + b;
        odd_taken = true;
      } else {
        b = c1 + b;
        b = c2 + b;
      }

      assert(make_palin(a)); // it is guaranteed that this is a palin
      palins.push_back({a, b});
      debug(palins);
    }

    sort(palins.begin(), palins.end());
    bool ok = false;
    for (auto [a, b] : palins) {
      if (make_palin(b)) {
        cout << "Case " << t << ": " << a << endl;
        ok = true;
        break;
      }
    }

    if (!ok)
      cout << "Case " << t << ": NO SOLUTION" << endl;
  }

  return 0;
}
