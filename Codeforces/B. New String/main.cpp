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
  string s;
  cin >> s;
  cin >> n;
  vector<string> ss(n);

  int p[26];

  for (int i = 0; i < 26; i++) {
    p[s[i] - 'a'] = i;
  }

  for (int i = 0; i < n; i++) {
    cin >> ss[i];
    for (ull j = 0; j < ss[i].size(); j++) {
      ss[i][j] = 'a' + p[ss[i][j] - 'a'];
    }
  }

  sort(all(ss));

  int k;
  cin >> k;
  string ans = ss[k - 1];
  for (ull j = 0; j < ans.size(); j++) {
    ans[j] = s[ans[j] - 'a'];
  }
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
