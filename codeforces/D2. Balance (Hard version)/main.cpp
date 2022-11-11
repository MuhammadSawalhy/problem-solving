// Date: 25-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int q;
  cin >> q;

  map<long long, long long> last;
  map<long long, priority_queue<long long, vector<long long>, greater<vector<long long>>>> other;
  set<long long> s;
  while (q--) {
    char t;
    long long x;
    cin >> t >> x;
    if (t == '+') {
      s.insert(x);
    } else if (t == '-') {

    } else {
      if (other[x].size()) {
        cout << other.
      }
    }
  }

  return 0;
}
