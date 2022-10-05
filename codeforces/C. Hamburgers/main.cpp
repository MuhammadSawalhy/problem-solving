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
  string recipe;
  cin >> recipe;

  ull rb = 0, rs = 0, rc = 0;
  for (char ch : recipe) {
    if (ch == 'B')
      rb++;
    if (ch == 'S')
      rs++;
    if (ch == 'C')
      rc++;
  }

  ull b, s, c;
  cin >> b >> s >> c;
  ull pb, ps, pc;
  cin >> pb >> ps >> pc;

  ull r;
  cin >> r;

  ull n = 0;
  while (true) {
    ull nn = INT_MAX;
    if (rb > 0)
      nn = min(nn, b / rb);
    if (rs > 0)
      nn = min(nn, s / rs);
    if (rc > 0)
      nn = min(nn, c / rc);

    b -= rb * nn;
    s -= rs * nn;
    c -= rc * nn;
    n += nn;

    if ((b == 0 || rb == 0) && (s == 0 || rs == 0) && (c == 0 || rc == 0)) {
      ull p = rb * pb + rs * ps + rc * pc;
      n += r / p;
      break;
    }

    if (rb > 0 && b / rb == 0 && (rb - b) * pb <= r) {
      r -= (rb - b) * pb;
      b = rb;
    } else if (rs > 0 && s / rs == 0 && (rs - s) * ps <= r) {
      r -= (rs - s) * ps;
      s = rs;
    } else if (rc > 0 && c / rc == 0 && (rc - c) * pc <= r) {
      r -= (rc - c) * pc;
      c = rc;
    } else {
      break;
    }
  }

  cout << n << endl;
}

void bs() {
  string recipe;
  cin >> recipe;
  int rb = 0, rs = 0, rc = 0;
  int nb, ns, nc;
  int pb, ps, pc;
  long long r;
  for (int i = 0; i < (int)recipe.size(); i++) {
    if (recipe[i] == 'B')
      rb++;
    if (recipe[i] == 'S')
      rs++;
    if (recipe[i] == 'C')
      rc++;
  }
  cin >> nb >> ns >> nc;
  cin >> pb >> ps >> pc;
  cin >> r;

  auto valid = [&](long long num) {
    long long p = max(num * rb - nb, 0LL) * pb + max(num * rs - ns, 0LL) * ps +
                  max(num * rc - nc, 0LL) * pc;
    return p <= r;
  };

  long long s = 0, e = 1;
  while (valid(e))
    e *= 2;
  while (s < e) {
    long long mid = (s + e + 1) >> 1;
    debug(s, e, mid);
    if (valid(mid)) {
      s = mid;
    } else {
      e = mid - 1;
    }
  }

  cout << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // solve();
  bs();
  return 0;
}
