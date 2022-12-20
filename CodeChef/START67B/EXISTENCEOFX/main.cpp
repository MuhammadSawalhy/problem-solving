// Date: 30-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef LOCAL
#include "debug.hpp"
#endif

void solve() {
  int A, B, C;
  cin >> A >> B >> C;

  bitset<30> a(A);
  bitset<30> b(B);
  bitset<30> c(C);

  map<int, bool> carryshouldbe{
          {0, 0},
          {1, 1},
          {2, 1},
          {3, 0},
          {4, 1},
          {5, 0},
          {6, 0},
          {7, 1},
  };

  int carry = 0;
  for (int i = 0; i < 30; i++) {
    int state = a[i] << 2 | b[i] << 1 | c[i];
    if (carry == carryshouldbe[state]) {
      // x[i] = 0
      carry = carry && (a[i] || b[i]) || (a[i] && b[i]);
    } else if (carry == carryshouldbe[state ^ 7]) {
      // x[i] = 1
      carry = carry && (!a[i] || !b[i]) || (!a[i] && !b[i]);
    } else {
      cout << "NO" << endl;
    }
  }

  if (carry) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
