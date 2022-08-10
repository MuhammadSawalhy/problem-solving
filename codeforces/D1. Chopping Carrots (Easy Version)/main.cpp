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

int n, k;
int a[3000];
int poss[3001];

void solve() {
  cin >> n >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  if (n == 1) {
    cout << 0 << endl;
    return;
  }

  for (int i = 1; i <= k; i++)
    poss[i] = a[0] / i;

  int ans = INT_MAX;

  for (int p1 = 1; p1 <= k; p1++) {
    int curans = INT_MIN;

    for (int i = 1; i < n; i++) {
      int myp, d = INT_MAX;
      if (poss[p1] == 0)
        myp = k;
      else
        myp = min(k, a[i] / poss[p1]);
      if (myp == 0)
        myp++;
      d = min(d, abs(a[i] / myp - poss[p1]));
      if (myp > 1)
        myp--;
      d = min(d, abs(a[i] / myp - poss[p1]));
      curans = max(curans, d);
    }

    ans = min(curans, ans);
    debug(ans, p1);
  }

  cout << ans << endl;
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
