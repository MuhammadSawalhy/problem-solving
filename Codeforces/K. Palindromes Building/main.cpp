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

int n;
string str;
array<int, 26> cnt;
map<pair<ull, ull>, ull> memo;

ull maxpalin() {
  ull key1 = 0;
  ull key2 = 0;
  for (int i = 0; i < 16; i++)
    key1 |= (ull)cnt[i] << i * 4;
  for (int i = 16; i < 26; i++)
    key2 |= (ull)cnt[i] << (i - 16) * 4;

  ull &c = memo[{key1, key2}];
  if (c)
    return c;

  int a = 0;
  for (int i = 0; i < 26; i++) {
    if (cnt[i]) {
      a++;
      cnt[i]--;
      c += maxpalin();
      cnt[i]++;
    }
  }

  if (a == 1)
    return c = 1;
  return c;
}

void solve() {
  cin >> n;
  cin >> str;
  fill(all(cnt), 0);
  memo.clear();
  for (int i = 0; i < str.size(); i++)
    cnt[str[i] - 'a']++;

  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  int odds = 0;

  for (int i = 0; i < 26; i++) {
    if (cnt[i] & 1)
      odds++;
  }

  if (odds > 1) {
    cout << 0 << endl;
    return;
  }

  for (int i = 0; i < 26; i++) {
    cnt[i] /= 2;
  }

  cout << maxpalin() << endl;
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
