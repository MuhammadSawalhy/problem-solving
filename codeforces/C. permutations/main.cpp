// Date: 26-10-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifndef ONLINE_JUDGE
#include "debug.hpp"
#endif

void solve() {
  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  while (q--) {
    string type;
    int x;
    cin >> type >> x;

    if (type == "next_permutation") {
      while (x--) {
        next_permutation(all(s));
      }
    } else {
      while (x--) {
        prev_permutation(all(s));
      }
    }

    cout << s << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  solve();

  return 0;
} 
