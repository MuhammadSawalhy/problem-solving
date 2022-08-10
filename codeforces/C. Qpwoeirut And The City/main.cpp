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

int n;
vi h;
vector<array<int, 2>> memo;

int minforeven(int i, bool is0taken) {
  if (i > n - 2)
    return 0;

  int &res = memo[i][is0taken];
  if (res != -1)
    return res;

  res = minforeven(i + 2, is0taken);

  int newh = h[i];
  if (newh <= h[i - 1])
    newh = h[i - 1] + 1;
  if (newh <= h[i + 1])
    newh = h[i + 1] + 1;
  res += newh - h[i];

  if (!is0taken) {
    int resss;
    i++;

    resss = minforeven(i + 2, true);

    int newh = h[i];
    if (newh <= h[i - 1])
      newh = h[i - 1] + 1;
    if (newh <= h[i + 1])
      newh = h[i + 1] + 1;
    resss += newh - h[i];

    res = min(res, resss);
  }

  return res;
}

int minforodd() {
  int res = 0;

  for (int i = 1; i < n; i += 2) {
    int newh = h[i];
    if (newh <= h[i - 1])
      newh = h[i - 1] + 1;
    if (newh <= h[i + 1])
      newh = h[i + 1] + 1;
    res += newh - h[i];
  }

  return res;
}

void solve() {
  cin >> n;
  h = vi(n);
  memo = vector<array<int, 2>>(n, array<int, 2>({-1, -1}));

  for (auto &i : h)
    cin >> i;

  if (n & 1)
    std::cout << minforodd() << std::endl;
  else
    std::cout << minforeven(1, false) << std::endl;
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
