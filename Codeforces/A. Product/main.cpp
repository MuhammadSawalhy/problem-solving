#include <bits/stdc++.h>

using namespace std;

// clang-format off
#ifndef ONLINE_JUDGE
#include "/home/ms/myp/problem-solving/debug.hpp"
#else
#define debug(x...)
#define debug_arr(arr, n)
#endif

typedef long long ll;
typedef unsigned long ul;
typedef unsigned long long ull;

#define f(i, a, b) for (ll i = a; i < b; i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(x) (ll)(x).size()
#define pop_cnt(x) (__builtin_popcountll(x))
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
#define int ll

template <class T> inline void clear(T *arr, int val, int n) { while(n--) arr[n] = val; }
// clang-format on

int getit(string &s, int i) {
  if (i >= s.size())
    return 0;
  return stoi(s.substr(i, 1));
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string a, b;

  while (cin >> a) {
    cin >> b;
    reverse(all(a));
    reverse(all(b));

    vector<int> p(500);

    for (int i = 0; i < a.size(); i++) {
      for (int k = 0; k < b.size(); k++) {
        p[i + k] += getit(a, i) * getit(b, k);
      }
    }

    for (int i = 0; i < p.size() - 1; i++) {
      p[i + 1] += p[i] / 10;
      p[i] %= 10;
    }

    int l = 500;
    for (int i = p.size() - 1; i > 0; i--) {
      if (p[i])
        break;
      l = i;
    }

    for (int i = l - 1; i >= 0; i--) {
      std::cout << p[i];
    }

    std::cout << std::endl;
  }

  return 0;
}
