// Date: 10-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;

  int n, x;
  cin >> n >> x;

  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if (i == x) continue;
    ans.push_back(i);
  }

  bool ok = true;
  do {
    ok = true;
    for (int i = 0; i < n - 2; i++) {
      if (ans[i] % (i + 2) != 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      break;
    }
  } while (next_permutation(all(ans)));

  int mainans;
  cin >> mainans;

  if (ok && mainans == -1) {
    exit(1);
  }

  return 0;
}
