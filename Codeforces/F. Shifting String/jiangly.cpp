#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#endif

using i64 = long long;

void solve() {
  int n;

  std::cin >> n;

  std::string s;
  std::cin >> s;

  std::vector<int> p(n);
  for (int i = 0; i < n; i++) {
    std::cin >> p[i];
    p[i]--;
  }

  i64 ans = 1;
  std::vector<bool> vis(n);
  for (int i = 0; i < n; i++) {
    if (vis[i])
      continue;

    std::string t;
    for (int j = i; !vis[j]; j = p[j]) {
      vis[j] = true;
      t += s[j];
    }

    std::cerr << "-------------------" << std::endl;
    std::cerr << "cycle: " << t << std::endl;

    int m = t.length();
    std::vector<int> f(m + 1);

    for (int i = 1, j = 0; i < m; i++) {
      while (j > 0 && t[i] != t[j]) {
        j = f[j];
      }
      if (t[i] == t[j]) {
        j++;
      }
      f[i + 1] = j;
      debug(j, i, f);
    }

    if (m % (m - f[m]) == 0) {
      ans = std::lcm(ans, m - f[m]);
    } else {
      ans = std::lcm(ans, m);
    }

    // same solution as main.py
    continue;

    auto shift = [](std::string t) {
      for (unsigned long i = 1; i <= t.length(); i++)
        if (t == t.substr(i) + t.substr(0, i))
          return i;
      return (unsigned long)0;
    };

    int ln = shift(t);
    ans = std::lcm(ln, ans);
  }

  std::cout << ans << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
