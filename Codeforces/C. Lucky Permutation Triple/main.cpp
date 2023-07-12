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

void print(vi &v) {
  for (int i = 0; i < n; i++) {
    cout << v[i] << " \n"[i == n - 1];
  }
}

void solve() {
  cin >> n;

  if (n % 2 == 0) {
    cout << -1 << endl;
    return;
  }

  vi c(n);
  for (int i = 0; i < n; i++) {
    c[i] = i;
  }

  vi a(c);
  reverse(all(a));

  vi b(n);

  for (int i = 0; i < n; i++) {
    b[i] = (c[i] - a[i] + n) % n;
  }

  print(a);
  print(b);
  print(c);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
