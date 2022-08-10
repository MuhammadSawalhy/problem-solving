#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(...)
#define debug_arr(...)
#define debug_bits(...)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define int ll
#define f(i, b) for (ll i = 0; i < b; i++)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define sum(v) accumulate(all(v), 0)
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)

typedef vector<int> vi;
typedef vector<bool> vb;

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int t_case;

void solve() {
  int a[200] = {};
  int b[200] = {};
  string A, B;

  cin >> A >> B;

  for (int i = 0; i < A.size(); i++) {
    a[i] = stoi(A.substr(i, 1));
  }

  for (int i = 0; i < B.size(); i++) {
    b[i] = stoi(B.substr(i, 1));
  }

  int sum[201] = {};
  for (int i = 0; i < 200; i++) {
    sum[i] += a[i] + b[i];
    sum[i + 1] += sum[i] / 10;
    sum[i] %= 10;
  }

  reverse(sum, sum + 201);

  int k = 0;
  while (sum[k] == 0)
    k++;

  bool ok = false;
  for (int i = 200; i >= k; i--) {
    if (sum[i])
      ok = true;
    if (!ok)
      continue;
    std::cout << sum[i];
    if (i == k)
      std::cout << endl;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t_case;
  while (t_case--)
    solve();
  return 0;
}
