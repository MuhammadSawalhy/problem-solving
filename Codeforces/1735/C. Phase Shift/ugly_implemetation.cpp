// Date: 02-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

void binary_search() {
  int n;
  string t;
  string s;
  cin >> n >> t;

  vector<deque<char>> enc;
  vector<bool> mapped(200);
  vector<bool> mapped_to(200);

  for (int i = 0; i < n; i++) {
    if (mapped[t[i]]) {
      for (auto &e : enc) {
        for (int j = 0; j < (int)e.size() - 1; j++) {
          if (e[j] == t[i]) {
            s += e[j + 1]; // this shouldn't cause problems
          }
        }
      }
    } else {
      // choose correct char and join slices
      for (char c = 'a'; c <= 'z'; c++) {
        if (mapped_to[c] || c == t[i])
          continue;

        if (mapped_to[t[i]]) {
          if (mapped[c]) {
            // can i join?
            bool ok = false;
            for (auto it = enc.begin(); it != enc.end(); it++) {
              if (it->back() != t[i])
                continue;
              for (auto ittt = enc.begin(); ittt != enc.end(); ittt++) {
                if (ittt->front() != c)
                  continue;

                if (it == ittt && it->size() == 26) {
                  // cycle
                  it->push_back(it->front());
                  ok = true;
                  goto line;
                } else if (it == ittt) {
                  goto line;
                }

                for (auto ch : *ittt)
                  it->push_back(ch);
                enc.erase(ittt);
                ok = true;
                goto line;
              }
            }

          line:;
            if (ok) {
              mapped[t[i]] = true;
              mapped_to[c] = true;
              s += c;
              break;
            }
          } else {
            for (auto &e : enc) {
              if (e.back() != t[i])
                continue;
              e.push_back(c);
              mapped[t[i]] = true;
              mapped_to[c] = true;
              s += c;
              break;
            }
            break;
          }
        } else {
          if (mapped[c]) {
            for (auto &e : enc) {
              if (e.front() == c) {
                e.push_front(t[i]);
                mapped[t[i]] = true;
                mapped_to[c] = true;
                s += c;
                break;
              }
            }
            break;
          } else {
            enc.push_back({t[i], c});
            mapped[t[i]] = true;
            mapped_to[c] = true;
            s += c;
            break;
          }
        }
      }
    }
  }

  // debug(enc);

  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    binary_search();
  }
  return 0;
}
