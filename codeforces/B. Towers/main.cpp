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
  int n, k;
  cin >> n >> k;

  pair<int, int> h[100];
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    h[i] = {i + 1, j};
  }

  sort(h, h + n, [](auto l, auto r) { return r.second > l.second; });

  int j = 0;
  int i = n - 1;

  while (j < n - 1 && h[j].second == h[j + 1].second)
    j++;
  while (i > 0 && h[i].second == h[i - 1].second)
    i--;

  int inik = k;
  vector<pair<int, int>> ops;
  debug_itr(h, h + n);
  debug(i, j);
  while (k--) {

    if (h[i].second - h[j].second <= 1)
      break;

    ops.push_back({h[i].first, h[j].first});

    h[j--].second++;
    h[i++].second--;

    if (j == -1) {
      j++;
      while (j < n - 1 && h[j].second == h[j + 1].second)
        j++;
    }

    if (i == n) {
      i--;
      while (i > 0 && h[i].second == h[i - 1].second)
        i--;
    }

    debug_itr(h, h + n);
    debug(i, j);
    debug(ops);
  }

  k++;

  cout << h[n - 1].second - h[0].second << " " << inik - k << endl;
  for (auto &[i, j] : ops)
    cout << i << " " << j << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
