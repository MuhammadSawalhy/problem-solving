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

void solve() {
  int n;
  cin >> n;
  vi c(n);
  for (auto &i : c) {
    int j;
    cin >> j;
    i = j - 1;
  }

  vi r(n);
  vi coutner(n);
  vi last(n, -1);
  debug(c);
  for (int i = 0; i < n; i++) {
    if (last[c[i]] == -1 || last[c[i]] == i - 1) {
      last[c[i]] = i;
      coutner[c[i]]++;
      continue;
    }

    if ((i - last[c[i]]) % 2 == 1) {
      last[c[i]] = i;
      coutner[c[i]]++;
      continue;
    }
  }

  for (int i = 0; i < n; i++) {
    cout << coutner[i] << " \n"[i == n - 1];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_case;
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
