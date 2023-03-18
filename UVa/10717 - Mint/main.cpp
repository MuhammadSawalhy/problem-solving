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

ull lcm(ull a, ull b, ull c, ull d) {
  ull ans = 1;
  ans = ans * a / __gcd(ans, a);
  ans = ans * b / __gcd(ans, b);
  ans = ans * c / __gcd(ans, c);
  ans = ans * d / __gcd(ans, d);
  return ans;
}

void solve() {
  ull n, t;
  while (true) {
    cin >> n >> t;
    if (n == 0)
      break;

    vi l;
    vi c(n);
    for (int &i : c)
      cin >> i;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
          for (int w = k + 1; w < n; w++) {
            l.push_back(lcm(c[i], c[j], c[k], c[w]));
          }
        }
      }
    }

    while (t--) {
      int h;
      cin >> h;
      ull a = 0, b = LONG_LONG_MAX;

      for (ull lc : l) {
        a = max(a, h / lc * lc);
        b = min(b, (ull)ceil((double)h / lc) * lc);
      }

      cout << a << " " << b << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
