// ----------------------------------------------------------------------------
// Problem : C. Permutation Game
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

int n;
vi a;
vi memo;

bool wins(int i) {
  int &w = memo[i];
  if (w != -1)
    return w;

  w = false;

  for (int j = i + a[i]; j < n; j += a[i]) {
    if (a[j] > a[i] && !wins(j)) {
      w = true;
      break;
    }
  }

  if (!w)
    for (int j = i - a[i]; j >= 0; j -= a[i]) {
      if (a[j] > a[i] && !wins(j)) {
        w = true;
        break;
      }
    }

  return w;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  a.resize(n);
  memo.assign(n, -1);
  for (auto &i : a)
    cin >> i;

  for (int i = 0; i < n; i++)
    cout << (wins(i) ? 'A' : 'B');
  cout << endl;
  return 0;
}
