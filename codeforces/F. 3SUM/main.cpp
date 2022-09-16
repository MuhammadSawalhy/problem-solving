//============================================================================
// Problem     : F. 3SUM
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

const int N = 2e5 + 1;
int n;
int a[N];

void solve() {
  cin >> n;
  map<int, int> fr;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    int d = a[i] % 10;
    if (fr[d] == 3)
      continue;
    nums.push_back(d);
    fr[d]++;
  }

  for (int i = 0; i < nums.size(); i++) {
    for (int j = i + 1; j < nums.size(); j++) {
      for (int k = j + 1; k < nums.size(); k++) {
        if ((nums[i] + nums[j] + nums[k]) % 10 == 3) {
          cout << "YES" << endl;
          return;
        }
      }
    }
  }

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
