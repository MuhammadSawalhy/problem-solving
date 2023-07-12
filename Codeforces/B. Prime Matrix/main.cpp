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

void sieve(vector<bool> &is_prime) {
  is_prime[1] = false;
  is_prime[0] = false;
  for (ull i = 4; i < sz(is_prime); i += 2)
    is_prime[i] = false;
  for (ull i = 3; i * i < sz(is_prime); i++) {
    if (is_prime[i]) {
      for (ull j = i * i; j < sz(is_prime); j += i + i)
        is_prime[j] = false;
    }
  }
}

void solve() {
  int n, m;
  cin >> n >> m;

  vb is_prime(1e5, true);
  sieve(is_prime);

  vi next_prime(1e5 + 1);
  next_prime[1e5] = 100003;
  for (int i = 1e5 - 1; i >= 1; i--) {
    if (is_prime[i])
      next_prime[i] = i;
    else
      next_prime[i] = next_prime[i + 1];
  }

  vector<vi> mat(n, vi(m));
  vector<vi> tam(n, vi(m));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      tam[i][j] = next_prime[mat[i][j]] - mat[i][j];
    }
  }

  ull ans = LONG_LONG_MAX;

  // over rows
  for (int i = 0; i < n; i++) {
    ull subans = 0;
    for (int j = 0; j < m; j++)
      subans += tam[i][j];
    ans = min(ans, subans);
  }

  debug(mat);
  debug(tam);

  // over cols
  for (int j = 0; j < m; j++) {
    ull subans = 0;
    for (int i = 0; i < n; i++)
      subans += tam[i][j];
    ans = min(ans, subans);
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
