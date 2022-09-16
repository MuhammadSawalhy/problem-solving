// ----------------------------------------------------------------------------
// Problem : D. Dividing Island
// Author  : Muahmmad Assawalhy
// Date    : 15-09-22
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
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  vi x(n);
  for (auto &i : x)
    cin >> i;
  cout << "YES" << endl;
  vector<vector<char>> island(max(b, d), vector<char>(a + c, '.'));

  auto valid = [&](int j, int k) {
    if (!(j >= 0 && j < max(b, d) && k >= 0 && k < a + c))
      return false;
    if (b > d && j >= d && k >= a)
      return false;
    if (d > b && j >= b && k < a)
      return false;
    return island[j][k] == '.';
  };

  auto next = [&](int &j, int &k) {
    if (valid(j + 1, k)) {
      j++;
    } else if (valid(j, k - 1)) {
      k--;
    } else if (valid(j, k + 1)) {
      k++;
    } else if (valid(j - 1, k)) {
      j--;
    } else {
      for (int i = 0; i < a + c; i++) {
        if (valid(j, i)) {
          k = i;
          return;
        }
      }
    }
  };

  int k = 0, j = max(b, d) - 1;
  if (d > b)
    k = a + c - 1;
  for (int i = 0; i < n; i++) {
    while (x[i]) {
      island[j][k] = 'a' + i;
      next(j, k);
      x[i]--;
    }
  }

  for (int i = 0; i < (int)island.size(); i++) {
    for (int j = 0; j < (int)island[0].size(); j++)
      cout << island[i][j];
    cout << endl;
  }

  return 0;
}
