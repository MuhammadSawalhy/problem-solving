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
  cin.get();

  vi d;

  while (n--) {
    char c = cin.get();
    int i = c - '0';
    if (i > 1)
      d.push_back(i);
  }

  vi ans;

  for (int i : d) {
    switch (i) {
    case 4:
      ans.push_back(3);
      ans.push_back(2);
      ans.push_back(2);
      break;
    case 6:
      ans.push_back(3);
      ans.push_back(5);
      break;
    case 8:
      ans.push_back(7);
      ans.push_back(2);
      ans.push_back(2);
      ans.push_back(2);
      break;
    case 9:
      ans.push_back(7);
      ans.push_back(3);
      ans.push_back(3);
      ans.push_back(2);
      break;
    default:
      ans.push_back(i);
      break;
    }
  }

  sort(rall(ans));

  for (int i = 0; i < sz(ans); i++)
    cout << ans[i];
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
