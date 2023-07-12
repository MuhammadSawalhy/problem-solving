// ----------------------------------------------------------------------------
// Problem : C. Jatayu's Balanced Bracket Sequence
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

struct union_find {
  vector<int> rank, parent;
  int forests;

  union_find(int n) {
    forests = n;
    rank = vector<int>(n);
    parent = vector<int>(n);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  bool connected(int x, int y) { return find(x) == find(y); }

  int find(int x) {
    if (parent[x] == x)
      return x;
    return parent[x] = find(parent[x]);
  }

  bool uni(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)
      return false;
    forests--;
    if (rank[y] > rank[x])
      swap(x, y);
    parent[y] = x;
    if (rank[x] == rank[y])
      rank[x]++;
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    int n;
    cin >> n;
    union_find uf(n << 1);
    string br;
    cin >> br;
    vector<int> ind;
    for (int i = 0; i < n << 1; i++) {
      if (br[i] == '(') {
        ind.push_back(i);
      } else {
        uf.uni(ind.back(), i);
        int last = ind.back();
        ind.pop_back();
        if (last > 0 && br[last - 1] == ')') {
          uf.uni(last - 1, i);
        }
      }
    }

    cout << uf.forests << endl;
  }
  return 0;
}
