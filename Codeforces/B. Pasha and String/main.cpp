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

void solve() {
  string s;
  int m;
  cin >> s >> m;

  vi a(m);
  for (auto &i : a)
    cin >> i;
  sort(all(a));

  for (int i = 0; i < sz(s) / 2; i++) {
    bool isswapped = distance(upper_bound(all(a), i + 1), a.begin()) & 1;
    if (isswapped)
      swap(s[i], s[sz(s) - 1 - i]);
  }

  std::cout << s << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
