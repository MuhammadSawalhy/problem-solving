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
typedef unsigned long ul;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

void solve() {
  int n, m;
  cin >> n >> m;
  vi a(n);
  vi b(m);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i] = 1 << b[i];
  }

  sort(all(a));
  sort(all(b));

  int i = 0, j = 0;

  for (int i = 0; i < n; i++) {
    if (b[j] != 1)
      break;
    if (a[i] & 1) {
      a[i]--;
      j++;
    }
  }

  while (i < n && j < m) {
    if (a[i] >= b[j]) {
      a[i] -= b[j];
      j++;
    } else {
      i++;
    }
  }

  cout << j << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
