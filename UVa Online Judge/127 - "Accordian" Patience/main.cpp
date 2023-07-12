// Date: 03-10-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

bool same(string s, string t) { return (s[0] == t[0] || s[1] == t[1]); }

void binary_search() {
  while (true) {
    vector<vector<string>> cards;
    string c;
    cin >> c;
    if (c == "#")
      break;
    cards.push_back({c});

    for (int i = 1; i < 52; i++) {
      cin >> c;
      cards.push_back({c});
    }

    auto doit = [&]() -> bool {
      bool something_done = false;

      for (int i = 1; i < cards.size(); i++) {
        if (i > 2 && same(cards[i - 3].back(), cards[i].back())) {
          something_done = true;
          cards[i - 3].push_back(cards[i].back());
          cards[i].pop_back();
          if (cards[i].empty())
            cards.erase(cards.begin() + i);
          break;
        } else if (i > 0 && same(cards[i - 1].back(), cards[i].back())) {
          something_done = true;
          cards[i - 1].push_back(cards[i].back());
          cards[i].pop_back();
          if (cards[i].empty())
            cards.erase(cards.begin() + i);
          break;
        }
      }

      return something_done;
    };

    while (doit())
      ;
    if (cards.size() == 1)
      cout << cards.size() << " pile remaining:";
    else
      cout << cards.size() << " piles remaining:";
    for (auto pile : cards)
      cout << " " << pile.size();
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  // cin >> t_cases;
  while (t_cases--) {
    binary_search();
  }
  return 0;
}
