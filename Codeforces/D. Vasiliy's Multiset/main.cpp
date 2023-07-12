// Date: 25-09-22
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_itr(...)
#define debug_bits(...)
#endif

vector<array<int, 2>> trie(1); // for 0, 1 and each int will be a index of nodes
vector<array<int, 2>> counts;  // for 0, 1

void solve() {
  char c;
  int x;
  cin >> c >> x;

  if (c == '+') {
    int node = 0;
    for (int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;
      if (trie[node][b] == 0) {
        trie.push_back({0, 0});
        counts.push_back({0, 0});
        trie[node][b] = trie.size() - 1;
      }
      counts[node][b]++;
      node = trie[node][b];
    }
  } else if (c == '-') {
    int node = 0;
    for (int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;
      assert(counts[node][b]);
      counts[node][b]--;
      node = trie[node][b];
    }
  } else {
    int node = 0;
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
      int b = (x >> i) & 1;
      if (counts[node][!b]) {
        debug("YES", i, b);
        ans |= !b << i;
        node = trie[node][!b];
      } else {
        debug("NO", i, b);
        ans |= b << i;
        node = trie[node][b];
      }
    }
    cout << (ans ^ x) << endl;
  }

  debug(trie);
  debug(counts);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int node = 0;
  for (int i = 31; i >= 0; i--) {
    int b = 0;
    if (trie[node][b] == 0) {
      trie.push_back({0, 0});
      counts.push_back({0, 0});
      trie[node][b] = trie.size() - 1;
    }
    counts[node][b]++;
    node = trie[node][b];
  }

  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    solve();
  }
  return 0;
}
