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

const int mod = 1e9 + 7;

void solve() {
  int n;
  cin >> n;
  unordered_map<int, int> fr;
  int a[n];
  int s[n];
  int m = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s[i] = a[i];
    fr[a[i]]++;
    m = max(m, a[i]);
  }

  sort(s, s + n);

  for (int i = 0; i < n; i++) {
    int j = upper_bound(s, s + n, mod - 1 - a[i]) - s;
    int b;

    if (j == 0) {
      b = m;
    } else {
      b = s[j - 1];
    }

    if (b == a[i] && fr[a[i]] == 1) {
      j = lower_bound(s, s + n, b) - s;
      j--;
      if (j < 0)
        b = m;
      else
        b = s[j];
    }

    cout << (a[i] + b) % mod << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t_cases;
  cin >> t_cases;
  while (t_cases--)
    solve();
  return 0;
}
