// ----------------------------------------------------------------------------
// Problem : A. Competitive Programmer
// Author  : Muahmmad Assawalhy
// Date    : 04-09-22
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
  int t_cases = 1;
  cin >> t_cases;
  while (t_cases--) {
    string n;
    cin >> n;

    int two = 0, three = 0, ten = 0;
    int s = 0;

    for (int i = 0; i < n.size(); i++) {
      int d = stoi(n.substr(i, 1));
      s += d;
      if (d % 2 == 0)
        two++;
      if (d == 0)
        ten++;
    }

    debug(n, s);
    if (s % 3 == 0)
      three = 1;

    cout << ((two && three && ten && (ten + two != 2)) ? "red" : "cyan") << endl;
  }
  return 0;
}
