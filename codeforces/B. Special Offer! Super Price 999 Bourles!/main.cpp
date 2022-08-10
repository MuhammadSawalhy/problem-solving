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
  ll p, d;
  cin >> p >> d;

  ll inip = p;
  ll nxtp = p;

  ll nines = 1;
  while (inip - nxtp <= d) {
    p = nxtp;
    debug(p);

    if (p / nines % 10 != 9) {
      nxtp -= nines * 10;
      nxtp -= p / nines % 10 * nines;
      nxtp += 9 * nines;
    }

    nines *= 10;
  }

  cout << p << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
