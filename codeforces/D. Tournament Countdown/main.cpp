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

int q(int p1, int p2) {
  int res;
  cout << "? " << p1 << " " << p2 << endl;
  cin >> res;
  if (res == 1)
    return p1;
  if (res == 2)
    return p2;
  return 0;
}

void solve() {
  int n;
  cin >> n;

  vi p((1 << n) + 1);

  for (int i = 0; i < sz(p); i++) {
    p[i] = i;
  }

  while (n > 1) {
    debug(p);

    for (int i = 1; i <= (1 << n); i += 4) {
      int r1 = q(p[i], p[i + 2]);
      if (r1 == 0) {
        p[i / 4 + 1] = q(p[i + 1], p[i + 3]);
      } else {
        if (r1 == p[i])
          p[i / 4 + 1] = q(p[i], p[i + 3]);
        else
          p[i / 4 + 1] = q(p[i + 1], p[i + 2]);
      }
    }

    n -= 2;
  }

  if (n == 1)
    p[1] = q(p[1], p[2]);

  cout << "! " << p[1] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
