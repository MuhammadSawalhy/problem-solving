// ----------------------------------------------------------------------------
// Problem : B. Pairs
// Author  : Muahmmad Assawalhy
// Date    : 09-09-22
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
  int n, m;
  cin >> n >> m;

  map<int, int> fr;
  map<pair<int, int>, int> dup;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b)
      swap(a, b);
    fr[a]++;
    fr[b]++;
    dup[{a, b}]++;
  }

  vector<pair<int, int>> vec;
  for (const auto &p : fr) {
    vec.emplace_back(p.second, p.first);
  }

  sort(all(vec));
  for (int i = vec.size() - 1; i >= 0; i--) {
    if (vec[i].first < m / 2)
      break;
    int j = lower_bound(all(vec), make_pair(m - vec[i].first, 0)) - vec.begin();
    for (int k = j; k < i; k++) {
      int how_many = vec[i].first + vec[k].first -
                     dup[{min(vec[i].second, vec[k].second),
                          max(vec[i].second, vec[k].second)}];
      if (how_many >= m) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }

  cout << "NO" << endl;

  return 0;
}
