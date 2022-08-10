#include "bits/stdc++.h"

using namespace std;

#define ll long long
const int MAXN = 3030;

int t, n, k;
int a[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> t;
  while (t--) {

    cin >> n >> k;
    for (int i = 0; i < n; i++)
      cin >> a[i];

    int ans = 1e9;
    for (int v = 1; v <= a[0]; v++) {

      int cm = v;
      for (int i = 0; i < n; i++) {
        int p = min(k, (v ? (a[i] / v) : k));
        cm = max(cm, a[i] / p);
      }

      ans = min(ans, cm - v);
    }

    cout << ans << "\n";
  }
}
