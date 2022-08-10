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
  int start = 1, end = 1e6;

  string ans;
  while (start < end) {
    int mid = (start + end + 1) >> 1;
    cout << mid << endl;
    cin >> ans;
    if (ans == ">=") {
      start = mid;
    } else {
      end = mid - 1;
    }
  }

  std::cout << "! " << end << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_case;
  solve();
  return 0;
}
