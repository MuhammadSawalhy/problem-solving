//============================================================================
// Problem     : G. Even-Odd XOR
// Author      : Muahmmad Assawalhy
// Date        : 31-08-22
//============================================================================

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
  // make sure that "odd" and "even" up till the 3rd from
  // the back doesn't equal each other, write the truth table starting from 0 to
  // better grasp it shift by one to make sure every they won't equal each other
  int counter = ((n - 2) % 4) == 0 || n == 3;
  vector<int> ans;
  int odd = 0, even = 0;

  for (int i = 0; i < n - 2; i++) {
    ans.push_back(counter++);
    if (i & 1)
      even ^= ans.back();
    else
      odd ^= ans.back();
  }

  int x = 1 << 29;

  if (n & 1) {
    ans.push_back(x ^ even);
    ans.push_back(x ^ odd);
  } else {
    ans.push_back(x ^ odd);
    ans.push_back(x ^ even);
  }

  for (int i = 0; i < n; i++)
    cout << ans[i] << " ";
  cout << endl;
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
