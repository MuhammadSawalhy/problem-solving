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

const ull MAX = 1e5;
const ull MAX_N = 2e7 + 20;
ull memo[MAX + 1];
ull last, last_twin;
bool is_prime[MAX_N + 1];

void sieve() {
  memset(is_prime, 1, sizeof(is_prime));
  for (ull i = 4; i <= MAX_N; i += 2)
    is_prime[i] = false;
  for (ull i = 3; i * i <= MAX_N; i++) {
    if (is_prime[i]) {
      for (ull j = i * i; j <= MAX_N; j += i + i)
        is_prime[j] = false;
    }
  }
}

void solve(int s) {
  while (last < s) {
    last_twin += 6;
    if (is_prime[last_twin] && is_prime[last_twin + 2]) {
      last++;
      memo[last] = last_twin;
    }

    last_twin += 2;
    if (is_prime[last_twin] && is_prime[last_twin + 2]) {
      last++;
      memo[last] = last_twin;
    }

    last_twin += 2;
    if (is_prime[last_twin] && is_prime[last_twin + 2]) {
      last++;
      memo[last] = last_twin;
    }
  }

  printf("(%llu, %llu)\n", memo[s], memo[s] + 2);
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  sieve();

  int s;
  memo[1] = 3;
  memo[2] = 5;
  memo[3] = 11;
  last = 3;
  last_twin = 11;

  while (cin >> s)
    solve(s);

  return 0;
}
