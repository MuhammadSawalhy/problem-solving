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
  int n;
  cin >> n;

  int f, c;
  cin >> f;
  n--;

  bool dec = false;
  int ok = true;

  while (n--) {
    cin >> c;

    if (!ok)
      continue;

    if (c < f) {
      dec = true;
    } else if (dec && c > f) {
      ok = false;
    }

    f = c;
  }

  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
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
