// Date: 13-10-2022
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#else
#define debug(...)
#endif

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<long long> b(n + 1);
  set<int> s;
  for (auto &i : a)
    cin >> i, s.insert(i);

  for (int i = 0; i < n; i++) {
    b[i + 1] = a[i];
    b[i + 1] += b[i];
  }

  vector<int> queries;

  while (q--) {
    int k;
    cin >> k;
    s.insert(k);
    queries.push_back(k);
  }

  vector<int> ss(s.begin(), s.end());
  map<int, int> mapper;
  for (int i = 1; i <= ss.size(); i++) {
    mapper[ss[i - 1]] = i;
  }

  for (int i = 0; i < queries.size(); i++) {
    queries[i] = mapper[queries[i]];
  }

  for (int i = 0; i < n; i++) {
    a[i] = mapper[a[i]];
  }

  vector<int> ps(5e5);

  int i = 0;
  for (int k = 0; k < ps.size(); k++) {
    while (i < n && a[i] <= k)
      i++;
    ps[k] = i;
  }

  for (auto qq : queries)
    cout << b[ps[qq]] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
