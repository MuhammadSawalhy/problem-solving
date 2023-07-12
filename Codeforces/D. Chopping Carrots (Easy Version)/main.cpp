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

int n, k;
int *a;

int get_cost(int t) {
  int p[n];

  for (int i = 0; i < n; i++) {
    p[i] = a[i];

    int d = abs(t - a[i]);
    for (int j = 2; j <= k; j++) {
      int dd = abs(t - a[i] / j);
      if (dd > d)
        break;
      else
        p[i] = a[i] / j;
      d = dd;
    }
  }

  int pmn = LONG_LONG_MAX, pmx = LONG_LONG_MIN;
  for (int i = 0; i < n; i++) {
    if (p[i] < pmn)
      pmn = p[i];
    if (p[i] > pmx)
      pmx = p[i];
  }

  return pmx - pmn;
}

void solve() {
  cin >> n >> k;
  a = (int *)malloc(sizeof(int) * n);

  int max = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > max) {
      max = a[i];
    }
  }

  int t = max / k;
  int cost = LONG_LONG_MAX;
  for (int i = 0; i <= max; i++) {
    cost = min(cost, get_cost(i));
  }

  free(a);
  std::cout << cost << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t_case;
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
