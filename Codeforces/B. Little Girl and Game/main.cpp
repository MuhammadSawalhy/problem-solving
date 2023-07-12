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
  string s;
  cin >> s;
  sort(all(s));
  char last = 0;
  int counter = 0;
  int numofodds = 0;

  for (int i = 0; i <= sz(s); i++) {
    if (i == sz(s) || s[i] != last) {
      if (counter & 1)
        numofodds++;
      last = s[i];
      counter = 0;
    }

    counter++;
  }

  int numofdeletions = max((int)0, numofodds - 1);
  debug(numofodds);
  debug(numofdeletions);

  if (numofdeletions & 1)
    std::cout << "Second" << std::endl;
  else
    std::cout << "First" << std::endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
