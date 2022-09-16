// ----------------------------------------------------------------------------
// Problem : B. Queue
// Author  : Muahmmad Assawalhy
// Date    : 15-09-22
// ----------------------------------------------------------------------------

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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef unsigned long long ull;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vi ans(n);
  map<int, int> m;
  map<int, int> mm;
  set<pair<int, int>> s;

  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    m[a] = b;
    mm[b] = a;
    s.insert({a, b});
  }

  int i = 1;
  int b, a = 0;
  while (i < n) {
    b = m[a];
    ans[i] = b;
    s.erase({a, b});
    a = b;
    i += 2;
  }

  s.erase({a, 0});

  auto rest = *s.begin();

  list<int> l;

  a = rest.second;
  while (a != 0) {
    l.push_back(a);
    a = m[a];
  }

  a = rest.first;
  while (a != 0) {
    l.push_front(a);
    a = mm[a];
  }

  i = 0;
  for (int x : l)
    ans[i] = x, i += 2;

  for (int i : ans)
    cout << i << " ";
  cout << endl;
  return 0;
}
