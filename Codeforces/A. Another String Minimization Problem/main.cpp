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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<char> s(m, 'B');

  for (int i = 0; i < n; i++) {
    int j;
    cin >> j;
    if (j - 1 < m - j && s[j - 1] != 'A') {
      s[j - 1] = 'A';
    } else if (s[m - j] != 'A') {
      s[m - j] = 'A';
    } else {
      s[j - 1] = 'A';
    }
  }

  for (int i = 0; i < m; i++)
    cout << s[i];
  std::cout << std::endl;
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
