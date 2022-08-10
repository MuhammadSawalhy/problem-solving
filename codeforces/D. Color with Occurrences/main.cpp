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
  string t;
  int n;
  cin >> t;
  cin >> n;
  vb c(sz(t));
  string s;

  set<array<int, 3>> ans;

  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 0; j < sz(t); j++) {
      if (s == t.substr(j, sz(s))) {
        vector<array<int, 3>> r;

        for (auto &p : ans) {
          if (p[1] >= j + 1 && p[2] <= j + s.size())
            r.push_back(p);
        }

        if (sz(r) > 1) {
          for (auto &p : r)
            ans.erase(p);
          ans.insert({i, j + 1, j + (int)s.size()});
          continue;
        }

        int ok = false;
        for (int k = j; k < j + sz(s); k++) {
          if (!c[k]) {
            ok = true;
            break;
          }
        }

        for (int k = j; k < j + sz(s); k++) {
          c[k] = true;
        }

        ans.insert({i, j + 1, j + (int)s.size()});
      }
    }
  }

  cout << sz(ans) << endl;
  for (auto &p : ans) {
    cout << p[0] << " " << p[1] << endl;
  }
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
