// ----------------------------------------------------------------------------
// Problem : 101 - The Blocks Problem
// Author  : Muahmmad Assawalhy
// Date    : 14-09-22
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
  while (cin >> n) {
    string x, y;
    int a, b;
    vector<vector<int>> blocks(n);
    vector<vector<int>> temp(n);
    for (int i = 0; i < n; i++)
      blocks[i].push_back(i);

    vi pos(n);
    iota(all(pos), 0);

    auto move = [&](int i, int j) {
      int a = blocks[i].back();
      blocks[i].pop_back();
      temp[j].push_back(a);
      pos[a] = j;
    };

    while (true) {
      cin >> x;
      if (x == "quit")
        break;
      cin >> a >> y >> b;

      if (pos[a] == pos[b])
        continue;

      if (x == "move") {
        while (blocks[pos[a]].back() != a) {
          move(pos[a], blocks[pos[a]].back()); // move to original position
        }
      }

      if (x == "onto") {
        while (blocks[pos[b]].back() != b) {
          move(pos[b], blocks[pos[b]].back()); // move to original position
        }
        move(pos[b], blocks[pos[b]].back()); // move to original position
      }

      while (blocks[pos[a]].back() != a)
        move(pos[a], pos[b]);
      move(pos[a], pos[b]);

      for (int i = 0; i < n; i++) {
        while (!temp[i].empty()) {
          blocks[i].push_back(temp[i].back());
          temp[i].pop_back();
        }
      }

      debug(blocks);
    }

    for (int i = 0; i < n; i++) {
      cout << i << ":";
      for (int j : blocks[i])
        cout << " " << j;
      cout << endl;
    }
  }

  return 0;
}
