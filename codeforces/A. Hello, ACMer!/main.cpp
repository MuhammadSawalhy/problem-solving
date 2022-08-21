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
  string s;
  cin >> s;

  const string mys = "hznu";

  int cnt = 0;
  for (int i = 0; i <= s.size() - mys.size(); i++) {
    if (s.substr(i, mys.size()) == mys) {
      cnt++;
    }
  }

  cout << cnt << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
    solve();
  return 0;
}
