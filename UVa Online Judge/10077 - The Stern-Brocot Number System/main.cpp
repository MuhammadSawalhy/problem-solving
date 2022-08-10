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

#define int ll
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)

void solve(int m, int n) {
  pair<int, int> right = {1, 0}, left = {0, 1}, pos;
  double targetFrac = (double)m / n;
  double frac;
  do {
    pos = {(right.first + left.first), (right.second + left.second)};
    frac = (double)pos.first / pos.second;
    if (targetFrac > frac) {
      cout << "R";
      left = pos;
    }

    if (targetFrac < frac) {
      cout << "L";
      right = pos;
    }
  } while (pos.first != m || pos.second != n);
  std::cout << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m, n;
  while (true) {
    cin >> m >> n;
    if (m == 1 && n == 1)
      break;
    solve(m, n);
  }
  return 0;
}
