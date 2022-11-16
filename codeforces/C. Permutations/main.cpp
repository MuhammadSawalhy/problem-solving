#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int n;
  cin >> n;
  int f[n], s[n];
  for (int i = 0; i < n; i++) cin >> f[i];
  for (int i = 0; i < n; i++) cin >> s[i];

  int j = n - 1;
  set<int> found;
  int k = n;
  for (int i = n - 1; ~i; i--) {
    if (found.count(s[i])) continue;
    while (j > 0 && f[j] != s[i]) {
      if (!found.count(f[j])) {
        found.insert(f[j]);
        k = j;
      }
      j--;
    }
    found.insert(f[j]);
  }

  cout << n - k << endl;

  return 0;
}
