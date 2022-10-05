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

struct union_find {
  vector<int> rank, parent, children;
  int forests;

  union_find(int n) {
    forests = n;
    rank = vector<int>(n);
    parent = vector<int>(n);
    children = vector<int>(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
    for (int i = 0; i < n; i++)
      children[i] = i;
  }

  bool connected(int x, int y) { return find(x) == find(y); }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  bool uni(int x, int y) {
    parent[y] = x;
    children[x] = y;
    forests--;
    return true;
  }
};

void dsu() {
  int n;
  string t;
  cin >> n >> t;

  string s;
  union_find uf(26);

  for (auto ch : t) {
    int chh = ch - 'a';
    // already mapped
    if (uf.children[chh] != chh) {
      s += 'a' + uf.children[chh];
      continue;
    }

    for (int c = 0; c < 26; c++) {
      if (uf.parent[c] != c)
        continue;
      if (!uf.connected(c, chh) || uf.forests == 1) {
        uf.uni(chh, c);
        s += 'a' + c;
        break;
      }
    }
  }

  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    dsu();
  }
  return 0;
}
