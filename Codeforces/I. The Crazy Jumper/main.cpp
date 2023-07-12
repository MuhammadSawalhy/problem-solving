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

#define N 200001

int n;
int c[N];
int memo[N];
map<int, vi> pos;

int dp(int i) {
  if (i == n - 1)
    return 0;
  int &r = memo[i];
  if (r != -1)
    return memo[i];
  r = dp(i + 1) + 1;
  auto &p = pos[c[i]];
  ull next = upper_bound(all(p), i) - p.begin();
  if (next < p.size()) {
    r = min(r, dp(p[next]) + 1);
  }
  return r;
}

void solve() {
  cin >> n;
  memset(memo, -1, n * sizeof(memo[0]));
  pos.clear();
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 0; i < n; i++)
    pos[c[i]].push_back(i);
  cout << dp(0) << endl;
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
