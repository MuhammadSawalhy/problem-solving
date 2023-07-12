// Date: 18-11-2022
#include <bits/stdc++.h>

using namespace std;

#define debug(...)
#define ll long long
#define all(v) v.begin(), v.end()
#ifdef SAWALHY
#include "debug.hpp"
#endif

void solve() {
  int n, p;
  cin >> n >> p;


  int a[n];
  int first, second;
  map<int, bool> ex;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ex[a[i]] = true;
  }

  first = a[n - 1], second = n > 1 ? a[n - 2] : 0;
  set<int> s(a, a + n);
  vector<int> b(all(s));

  int missing = p - (int)b.size();
  if (missing == 0) {
    cout << 0 << endl;
    return;
  }

  int mx = p - 1;
  while (ex[mx]) mx--, assert(mx >= 0);

  int cnt = 0;
  for (int i = 0; i < b.size(); i++) {
    if (b[i] > first) cnt++;
  }

  int ans = 0;
  missing -= p - (first + 1) - cnt;

  debug(first, second, cnt);

  if (missing == 0) {
    ans += mx - first;
  } else {
    ans += p - first;
    int next;
    int j = n - 2;
    do {
      second = ~j ? a[j] : 0;
      j--;
      next = (second + 1) % p;
      if (!ex[next] && next < first) {
        missing--;
        ex[next] = true;
        b.push_back(next);
      }
    } while (next == 0);
  }

  if (missing == 0) {
    cout << ans << endl;
    return;
  }


  int cnt2 = 0;
  int mx2 = first - 1;
  while (ex[mx2]) mx2--, assert(mx2 >= 0);
  for (int i = 0; i < b.size(); i++) {
    if (b[i] < first) cnt2++;
  }

  debug(mx2, cnt2, missing);
  ans += mx2;
  missing -= first - cnt2;

  assert(ans <= p);
  assert(missing == 0);
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
    solve();

  return 0;
}
