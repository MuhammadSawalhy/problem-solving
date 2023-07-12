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

void solve() {
  int n;
  cin >> n;
  map<int, int> seq;

  while (n--) {
    int x;
    cin >> x;
    if (seq[x - 1]) {
      seq[x] = max(seq[x], seq[x - 1] + 1);
      seq.erase(x - 1);
    } else
      seq[x] = max(seq[x], 1);
  }

  debug(seq);

  int ans = -1;
  for (auto &p : seq) {
    ans = max(ans, p.second);
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
