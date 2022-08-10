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

#define MAX 10000001
vb is_prime(MAX, 1);
vector<ull> prev_prime(MAX);

void sieve(vector<bool> &is_prime) {
  for (ull i = 4; i < sz(is_prime); i += 2)
    is_prime[i] = false;
  for (ull i = 3; i * i < sz(is_prime); i++) {
    if (is_prime[i]) {
      for (ull j = i * i; j < sz(is_prime); j += i + i)
        is_prime[j] = false;
    }
  }
}

void solve(ull n) {
  if (n < 8) {
    cout << "Impossible." << endl;
    return;
  }

  for (int i = 3; i >= 0; i--) {
    int pp = prev_prime[n - 2 * i];
    cout << pp << "\n   "[i];
    n -= pp;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  sieve(is_prime);

  ull pp;
  for (ull i = 2; i < MAX; i++) {
    if (is_prime[i])
      pp = i;
    prev_prime[i] = pp;
  }

  ull n;
  while (cin >> n)
    solve(n);

  return 0;
}
