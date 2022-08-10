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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    a[i].first = i + 1;
    a[i].second = j;
  }

  sort(all(a), [](auto l, auto r) {
    return r.second == l.second ? r.first > l.first : r.second > l.second;
  });

  vi order;
  int i = n - 1;
  while (true) {
    while (i > 0 && a[i - 1].second == a[i].second) {
      i--;
    }

    sort(a.begin() + i, a.end(), [](auto l, auto r) {
      return r.second == l.second ? r.first > l.first : r.second > l.second;
    });

    if (order.size() > 0 && order.back() == a[i].first) {
      swap(a[i], a[i + 1]);
    }

    for (int j = i; j < n; j++) {
      order.push_back(a[j].first);
      a[j].second--;
    }

    if (i == 0 && a[0].second == 0)
      break;

    if (i == n - 1 && a[i - 1].second != a[i].second) {
      cout << -1 << endl;
      return;
    }
  }

  cout << order[0];
  for (int i = 1; i < sz(order); i++)
    cout << " " << order[i];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
